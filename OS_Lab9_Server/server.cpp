#include "server.h"

#define _CRT_SECURE_NO_WARNINGS
#include <QDebug>

DWORD WINAPI receiveServent(LPVOID param)
{
    printf("THREAD receiveServent STATED\n");
    std::vector<Client>* clients = (std::vector<Client>*)param;

    while (true) {
        if (!revcMessageQueue.empty()) {

            WaitForSingleObject(mutexRecvMsg, INFINITY);
            ExtMessage msg = revcMessageQueue.front();
            revcMessageQueue.pop();
            ReleaseMutex(mutexRecvMsg);

            printf("Receive message: Client #%d: %s\n", msg.clientUID, msg.message);

            if (strlen(msg.message) >= 4) {
                if (strncmp(msg.message, "CCN:", 4) == 0) {
                    memmove(msg.message, msg.message + 4, strlen(msg.message) - 3);

                    bool isFound = false;
                    WaitForSingleObject(mutexClients, INFINITY);
                    for (auto& client : *clients) {
                        if (client.clientUID == msg.clientUID) {
                            strncpy_s(client.name, DEFAULT_NAMELEN, msg.message, DEFAULT_NAMELEN);
                            std::cout << "Client #" << client.clientUID << " name set: " << client.name << "\n";
                            isFound = true;
                            break;
                        }
                    }
                    ReleaseMutex(mutexClients);
                    if (!isFound)
                        printf("Error name setting. Can`t find Client#%d\n", msg.clientUID);
                }
                else if (strncmp(msg.message, "TGH:", 4) == 0) {
                    memmove(msg.message, msg.message + 4, strlen(msg.message) - 3);

                    Idea idea = { getUID(&TID), {0, ""}, 0 };
                    idea.message.clientUID = msg.clientUID;
                    strncpy_s(idea.message.message, sizeof(idea.message.message), msg.message, _TRUNCATE);
                    std::cout << "Add new idea #" << idea.ideaTID << "from Client #" << idea.message.clientUID << " : " << idea.message.message << "\n";

                    WaitForSingleObject(mutexIdeas, INFINITY);
                    ideaVector.push_back(idea);
                    ReleaseMutex(mutexIdeas);
                }
                else if (strncmp(msg.message, "RNK:", 4) == 0) {
                    memmove(msg.message, msg.message + 4, strlen(msg.message) - 3);

                    isVoted = true;
                    bool isFound = false;
                    WaitForSingleObject(mutexIdeas, INFINITY);
                    char* token = strtok(msg.message, " ");
                    while (token != nullptr) {
                        int TID = atoi(token);
                        for (int i = 0; i < ideaVector.size(); i++) {
                            if (ideaVector[i].ideaTID == TID) {
                                ideaVector[i].cntVoice++;
                                std::cout << "New vote counted: Idea #" << ideaVector[i].ideaTID << " voices new value: " << ideaVector[i].cntVoice << "\n";
                                isFound = true;
                                break;
                            }
                        }
                        token = strtok(nullptr, " ");
                        if (!isFound)
                            printf("Error new vote counting. Can`t find Idea#%d\n", TID);
                    }
                    ReleaseMutex(mutexIdeas);
                }
                else {
                    printf("Unknown command in receiveServent\n");
                }
            }
            else {
                printf("Too short command in receiveServent\n");
            }
        }
        else {
            Sleep(250);
        }
    }
    printf("THREAD receiveServent ENDED\n");
}

DWORD WINAPI checkAllAM(LPVOID param)
{
    std::vector<Client>* clients = (std::vector<Client>*)param;

    DWORD exitThreadCode = 0;
    while (true) {
        if (allAM(*clients) || timerOut) break;
        Sleep(SLEEP_TIME);
    }
    nonAM(*clients);

    if (timerOut)
        printf("timerOut in sending session.\n");
    else
        printf("allAM in sending session.\n");

    printf("Push sendMessage: ES\n");

    WaitForSingleObject(mutexSendMsg, INFINITE);
    sendMessageQueue.push("ES");
    ReleaseMutex(mutexSendMsg);

    timerOut = false;

    return exitThreadCode;
}

DWORD WINAPI rankIdeas(LPVOID param)
{
    UNREFERENCED_PARAMETER(param);
    while (isRanking) {
        if (isVoted) {
            WaitForSingleObject(mutexIdeas, INFINITY);
            std::sort(ideaVector.begin(), ideaVector.end(), [](const Idea& a, const Idea& b) {
                return a.cntVoice > b.cntVoice;
            });
            ReleaseMutex(mutexIdeas);
            isVoted = false;
        }
        Sleep(RERANK_TIME);
    }
    return 0;
}

DWORD WINAPI receiveMessages(LPVOID param) {
    Client* client = (Client*)param;

    char recvBuf[DEFAULT_BUFLEN];
    int  recvBufLen = DEFAULT_BUFLEN;

    int iResult;
    int exitCode = 0;
    while (true) {

        iResult = recv(client->clientSocket, recvBuf, recvBufLen, 0);

        if (iResult > 0) {
            recvBuf[iResult] = '\0';

            std::string message(recvBuf);
            if (message == "AM") {
                bool isFound = false;
                WaitForSingleObject(mutexClients, INFINITE);
                for (int i = 0; i < clients.size(); i++) {
                    if (clients[i].clientUID == client->clientUID) {
                        printf("Client #%d is AM\n", clients[i].clientUID);
                        clients[i].isAM = true;
                        isFound = true;
                        break;
                    }
                }
                ReleaseMutex(mutexClients);
                if (!isFound)
                    printf("Error setting AM. Can`t find Client #%d\n", client->clientUID);
            }
            else {
                ExtMessage msg = { client->clientUID, "" };
                strncpy_s(msg.message, iResult + 1, recvBuf, iResult);

                WaitForSingleObject(mutexRecvMsg, INFINITE);
                revcMessageQueue.push(msg);
                ReleaseMutex(mutexRecvMsg);
            }
        } else if (iResult == 0) {
            printf("Connection successfully closed by Client #%d\n", client->clientUID);
            exitCode = EXIT_CODE_RECV;
            break;
        } else {
            printf("recv from Client #%d failed with error code: %d\n", client->clientUID, WSAGetLastError());
            exitCode = RESV_MESS_FAIL;
            break;
        }
    }

    printf("Attempting to delete Client #%d from vector...\n", client->clientUID);

    WaitForSingleObject(mutexClients, INFINITE);
    int isDeleted = false;
    for (int i = 0; i < clients.size(); i++) {
        if (clients[i].clientUID == client->clientUID) {
            delFromVector(clients, i);
            isDeleted = true;
            break;
        }
    }
    ReleaseMutex(mutexClients);
    if (!isDeleted) printf("Client #%d not found to delete in vector\n", client->clientUID);

    return exitCode;
}

DWORD WINAPI listenClients(LPVOID param) {
    SOCKET* listenSocket = (SOCKET*)param;

    while (true) {
        SOCKET tempClientSocket = INVALID_SOCKET;
        tempClientSocket = accept(*listenSocket, NULL, NULL);

        if (tempClientSocket == INVALID_SOCKET) {
            printf("accept failed with error: %d\n", WSAGetLastError());
            closesocket(*listenSocket);
            WSACleanup();
            return 1;
        }

        Client* newClient = new Client;
        newClient->clientSocket = tempClientSocket;
        newClient->clientUID = getUID(&UID);
        newClient->threadHandle = CreateThread(
            NULL,
            0,
            receiveMessages,
            newClient,
            0,
            &(newClient->threadID)
            );

        if (newClient->threadHandle == NULL) {
            printf("Failed to create thread for client #%d.\n", newClient->clientUID);
            closesocket(tempClientSocket);
        }
        else {
            printf("Connected client #%d\n", newClient->clientUID);
            clients.push_back(*newClient);
        }
    }
    closesocket(*listenSocket);
}

int getUID(int* UID)
{
    WaitForSingleObject(mutexUI, INFINITE);
    int tempUID = ++(*UID);
    ReleaseMutex(mutexUI);

    return tempUID;
}

bool allAM(std::vector<Client>& clients) {
    bool isAllAM = true;
    WaitForSingleObject(mutexClients, INFINITE);
    for (int i = 0; i < clients.size(); i++) {
        if (clients[i].isAM == false) {
            isAllAM = false;
            break;
        }
    }

    if (isAllAM)
        printf("AllAM = true\n");

    ReleaseMutex(mutexClients);

    return isAllAM;
}

void nonAM(std::vector<Client>& clients) {
    WaitForSingleObject(mutexClients, INFINITE);
    for (int i = 0; i < clients.size(); i++) {
        clients[i].isAM = false;
    }
    ReleaseMutex(mutexClients);
}

int openListen() {

    int iResult = 0;
    int exitCode = 0;

    printf("Trying to open listening...\n");

    do {
        listenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
        if (listenSocket == INVALID_SOCKET) {
            printf("socket failed with error: %d\n", WSAGetLastError());
            exitCode = 1;
            break;
        }

        iResult = bind(listenSocket, result->ai_addr, (int)result->ai_addrlen);
        if (iResult == SOCKET_ERROR) {
            printf("bind failed with error: %d\n", WSAGetLastError());
            exitCode = 1;
            break;
        }

        iResult = listen(listenSocket, SOMAXCONN);
        if (iResult == SOCKET_ERROR) {
            printf("listen failed with error: %d\n", WSAGetLastError());
            exitCode = 1;
            break;
        }

        DWORD threadID_listen;
        ListenThread = CreateThread(
            NULL,
            0,
            listenClients,
            &listenSocket,
            0,
            &threadID_listen
            );

        if (ListenThread == NULL) {
            printf("Failed to create listening thread with error code: %d\n", (int)GetLastError());
        }
    } while (false);

    if (exitCode == 0)
        printf("Listening successfully opened\n");
    else
        printf("Error opening listening\n");

    return exitCode;
}

void closeListen(HANDLE& ListenThread, SOCKET& listenSocket) {
    TerminateThread(ListenThread, 0);
    CloseHandle(ListenThread);
    shutdown(listenSocket, SD_BOTH);
    closesocket(listenSocket);
    listenSocket = INVALID_SOCKET;
    printf("Listening closed\n");
}

void closeAllReceive(std::vector<Client>& clients, HANDLE& mutexClients) {
    printf("Closing connection with all clients...\n");
    WaitForSingleObject(mutexClients, INFINITE);
    for (int i = 0; i < clients.size(); i++) {
        closeOneReceive(clients, i);
        i--;
    }
    ReleaseMutex(mutexClients);
    printf("Connection with all clients successfully closed\n");
}

void closeOneReceive(std::vector<Client>& clients, int i) {
    int iResult = 0;
    DWORD exitCodeThread = 0;
    Client client = clients[i];
    if (GetExitCodeThread(client.threadHandle, &exitCodeThread)) {
        if (exitCodeThread == STILL_ACTIVE) {
            iResult = shutdown(client.clientSocket, SD_BOTH);
            if (iResult == SOCKET_ERROR) {
                printf("Shutdown client #%d failed with error code: %d\n", client.clientUID, WSAGetLastError());
            } else {
                printf("Connection with client #%d successfully closed by server\n", client.clientUID);
            }
        } else {
            printf("Client #%d already has leaved session", client.clientUID);
        }
    } else {
        printf("GetExitCodeThread client #%d failed with error code: %d\n", client.clientUID, (int)GetLastError());
    }


    // if (GetExitCodeThread(client.threadHandle, &exitCodeThread)) {
    //     if (exitCodeThread == STILL_ACTIVE) {
    //         std::cout << "Trying to terminate TerminateThread...\n";
    //         TerminateThread(client.threadHandle, 0);
    //         std::cout << "Thread terminated\n";
    //     }
    //     else {
    //         std::cout << "Thread is not alive\n";
    //     }
    // }

    delFromVector(clients,i);

    return;
}

void delFromVector(std::vector<Client>& clients, int i)
{
    std::cout << "Trying to delete from vector...\n";
    CloseHandle(clients[i].threadHandle);
    std::cout << "CloseHandle done\n";
    shutdown(clients[i].clientSocket, SD_BOTH);
    std::cout << "shutdown done\n";
    closesocket(clients[i].clientSocket);
    std::cout << "closesocket done\n";

    printf("Client deleted from vector\n");
    clients.erase(clients.begin() + i);
}

void closeClientWithUID(std::vector<Client>& clients, int UID) {
    bool isFound = false;

    for (int i = 0; i < clients.size(); i++) {
        if (clients[i].clientUID == UID) {
            printf("Client #%d found to delete.\n", UID);
            isFound = true;
            closeOneReceive(clients, i);
            printf("Client #%d closeOneReceive done.\n", UID);
            break;
        }
    }

    if (!isFound) {
        printf("Error deleting Client #%d. Unknown UID\n", UID);
    }
}

void deleteIdea(int TID) {
    WaitForSingleObject(mutexIdeas, INFINITY);
    int prevSize = (int)ideaVector.size();
    ideaVector.erase(
        std::remove_if(ideaVector.begin(), ideaVector.end(), [TID](const Idea& idea) {
            return idea.ideaTID == TID;
        }),
        ideaVector.end()
        );
    if (prevSize > (int)ideaVector.size())
        printf("Idea with TID: %d was sucessfully deleted\n", TID);
    else
        printf("Error deleting Idea #%d. Unknown TID\n", TID);

    ReleaseMutex(mutexIdeas);
}

void sendOneMessage(std::vector<Client>& clients, std::string message) {
    int iResult;
    DWORD exitCodeThread = 0;

    Sleep(300);
    WaitForSingleObject(mutexClients, INFINITE);
    for (int i = 0; i < clients.size(); i++) {
        int isContinue = false;
        if (GetExitCodeThread(clients[i].threadHandle, &exitCodeThread)) {
            if (exitCodeThread == STILL_ACTIVE) {
                iResult = send(clients[i].clientSocket, message.c_str(), (int)message.length(), 0);
                if (iResult == SOCKET_ERROR) {
                    printf("Send message failed to client #%d with error code: %d\n", clients[i].clientUID, WSAGetLastError());
                }
                else {
                    isContinue = true;
                }
            }
            else {
                printf("Client #%d already has leaved session", clients[i].clientUID);
            }
        }
        else {
            printf("GetExitCodeThread client #%d failed with error code: %d\n", clients[i].clientUID, (int)GetLastError());
        }

        if (!isContinue) {
            TerminateThread(clients[i].threadHandle, 0);
            delFromVector(clients, i);
            i--;
        }
    }
    std::cout << "Send message: " << message << "\n";
    ReleaseMutex(mutexClients);
}

DWORD WINAPI sendMessages(LPVOID param) {
    std::vector<Client>* clients = (std::vector<Client>*)param;
    std::string message;
    int iResult;

    DWORD exitCode = 0;

    printf("\nTHREAD sendMessages started\n"
           "Waiting \"SS\" to start sending session.\n\n");

    while (true) {
        while (true) {
            if (!sendMessageQueue.empty()) break;
            Sleep(SLEEP_TIME);
        }
        WaitForSingleObject(mutexSendMsg, INFINITE);
        message = sendMessageQueue.front();
        sendMessageQueue.pop();
        ReleaseMutex(mutexSendMsg);

        std::cout << "Popped sendMessage: " << message << "\n";

        if (message == "SS") {
            closeListen(ListenThread, listenSocket);

            std::string topic;
            topic = "STP:" + sessionTopic;
            sendOneMessage(*clients, topic);

            std::string timer;
            timer = "STM:" + std::to_string(sessionTimeSec);
            sendOneMessage(*clients, timer);

            DWORD  allAMThreadID;
            allAMThread = CreateThread(
                NULL,
                0,
                checkAllAM,
                clients,
                0,
                &allAMThreadID
                );

            sendOneMessage(*clients, message);
            std::cout << "\nSending session started successfully.\n"
                         "Waiting \"ES\" to end the sending session \n"
                         "and move to the voting session.\n\n";

        } else if (message == "ES") {

            nonAM(*clients);
            DWORD exitCodeAllAMThread = 0;
            GetExitCodeThread(allAMThread, &exitCodeAllAMThread);
            if (exitCodeAllAMThread == STILL_ACTIVE) {
                TerminateThread(allAMThread, 0);
            }

            printf("The sending session is complete.\n"
                   "Waiting to receive all customer messages...\n\n");
            sendOneMessage(*clients, "ES");

            printf("ProgStage = ES\n");
            progStage = "ES";

            while (true) {
                if (allAM(*clients)) break;
                Sleep(500);
            }
            nonAM(*clients);

            printf("All user ideas successfully received.\n"
                    "Sending ideas list to clients...\n\n");

            WaitForSingleObject(mutexIdeas, INFINITY);
            for (int i = 0; i < ideaVector.size(); i++) {

                std::string idea;
                idea = "TGH:" + std::to_string(ideaVector[i].ideaTID);
                idea += " " + std::string(ideaVector[i].message.message);

                sendOneMessage(*clients, idea);
                Sleep(50);
            }
            ReleaseMutex(mutexIdeas);

            printf("Ideas list successfully sent.\n\n");

            DWORD threadID_rank;
            isRanking = true;
            RankThread = CreateThread(
                NULL,
                0,
                rankIdeas,
                NULL,
                0,
                &threadID_rank
                );

            sendOneMessage(*clients, "SV");
            printf("ProgStage = SV\n");
            progStage = "SV";

            printf("\nVoting session successfully started.\n"
                   "Waiting \"EV\" to end the voting session \n"
                   "and move to the results of session.\n\n");

            while (true) {
                if (allAM(*clients) || timerOut) break;
                Sleep(500);
            }

            if (timerOut)
                printf("timerOut in voting session.\n");
            else
                printf("allAM in voting session.\n");

            nonAM(*clients);
            timerOut = false;

            printf("Push message: EV\n");
            WaitForSingleObject(mutexSendMsg, INFINITE);
            sendMessageQueue.push("EV");
            ReleaseMutex(mutexSendMsg);

        } else if (message == "EV") {
            sendOneMessage(*clients, "EV");

            printf("\nVoting session ended.\n"
                    "Sending results to clients...\n\n");

            Sleep(RERANK_TIME);
            isRanking = false;

            printf("ProgStage = EV\n");
            progStage = "EV";

            for (int i = 0; i < (ideaVector.size() < 3 ? ideaVector.size() : 3); i++) {
                std::string idea;

                int UID = ideaVector[i].message.clientUID;
                std::string name = "unknown";
                WaitForSingleObject(mutexClients, INFINITE);
                for (int i = 0; i < clients->size(); i++) {
                    if ((*clients)[i].clientUID == UID) {
                        name = (*clients)[i].name;
                        break;
                    }
                }
                ReleaseMutex(mutexClients);

                idea =
                    "TP3:"                                  +
                    std::to_string(ideaVector[i].ideaTID )  + " " +
                    std::to_string(ideaVector[i].cntVoice)  + " " +
                    name                                    + "|" +
                    std::string(ideaVector[i].message.message);

                sendOneMessage(*clients, idea);
            }
            Sleep(100);
            printf("\nResult successfully send.\n"
                    "Ending the current session...\n\n");

            sendOneMessage(*clients, "TS");
            closeAllReceive(*clients, mutexClients);

            ideaVector.clear();
            clients->clear();
            TID = 0;
            UID = 0;
            isRanking = false;

            printf("\nCurrent session successfully ended.\n"
                    "Waiting \"RS\" to start new session.\n");

        } else if (message == "RS") {

            printf("\nTrying to start new session...\n\n");
            ideaVector.clear();
            clients->clear();
            TID = 0;
            UID = 0;
            isRanking = false;
            iResult = openListen();
            if (!iResult) {
                printf("\nNew session started successfully.\n"
                        "Waiting clients to connect...\n\n"
                        "Waiting \"SS\" to start sending session.\n\n");
            } else {
                printf("\nError while starting new session.\n");
            }
        }
    }

    closeListen(ListenThread, listenSocket);
    closeAllReceive(*clients, mutexClients);

    printf("\n\nTHREAD sendMessages ENDED\n\n");
    return exitCode;
}
