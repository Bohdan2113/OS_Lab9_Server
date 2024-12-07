#include "server.h"

DWORD WINAPI receiveServent(LPVOID param) {
    std::vector<Client>* clients = (std::vector<Client>*)param;

    while (true) {
        if (!revcMessageQueue.empty()) {

            WaitForSingleObject(mutexRecvMsg, INFINITY);
            ExtMessage msg = revcMessageQueue.front();
            revcMessageQueue.pop();
            ReleaseMutex(mutexRecvMsg);

            printf("\t\t\tClient #%d: %s\n", msg.clientUID, msg.message);

            if (strlen(msg.message) >= 4) {
                if (strncmp(msg.message, "CCN:", 4) == 0) {
                    memmove(msg.message, msg.message + 4, strlen(msg.message) - 3);
                    WaitForSingleObject(mutexClients, INFINITY);
                    for (auto& client : *clients) {
                        if (client.clientUID == msg.clientUID) {
                            strncpy_s(client.name, DEFAULT_NAMELEN, msg.message, DEFAULT_NAMELEN);
                            break;
                        }
                    }
                    ReleaseMutex(mutexClients);
                }
                else if (strncmp(msg.message, "TGH:", 4) == 0) {
                    memmove(msg.message, msg.message + 4, strlen(msg.message) - 3);

                    Idea idea = { getUID(&TID), NULL, 0 };
                    idea.message.clientUID = msg.clientUID;
                    strncpy_s(idea.message.message, sizeof(idea.message.message), msg.message, _TRUNCATE);

                    WaitForSingleObject(mutexIdeas, INFINITY);
                    ideaVector.push_back(idea);
                    ReleaseMutex(mutexIdeas);
                }
                else if (strncmp(msg.message, "RNK:", 4) == 0) {
                    memmove(msg.message, msg.message + 4, strlen(msg.message) - 3);
                    isVoted = true;
                    WaitForSingleObject(mutexIdeas, INFINITY);
                    char* token = strtok(msg.message, " ");
                    while (token != nullptr) {
                        int TID = atoi(token);
                        for (int i = 0; i < ideaVector.size(); i++) {
                            if (ideaVector[i].ideaTID == TID) {
                                ideaVector[i].cntVoice++;
                                break;
                            }
                        }
                        token = strtok(nullptr, " ");
                    }
                    ReleaseMutex(mutexIdeas);
                }
            }

        }
    }
}

DWORD WINAPI checkAllAM(LPVOID param) {
    std::vector<Client>* clients = (std::vector<Client>*)param;

    DWORD exitThreadCode = 0;
    while (true) {
        if (allAM(*clients) || timerOut) break;
        Sleep(SLEEP_TIME);
    }
    nonAM(*clients);

    WaitForSingleObject(mutexSendMsg, INFINITE);
    sendMessageQueue.push("ES");
    ReleaseMutex(mutexSendMsg);

    return exitThreadCode;
}

DWORD WINAPI inputMessages(LPVOID param) {
    DWORD exitThreadCode = 0;

    while (true) {
        std::string message;
        getline(std::cin, message);

        if (message == "SS") {

            if (clients.size() == 0) {
                printf("Wait for clients pls.\n");
                continue;
            }

            closeListen(ListenThread, listenSocket);

            printf("Enter topic of discussion:\n");
            std::string topic;
            getline(std::cin, topic);
            topic = "STP:" + topic;
            sendOneMessage(clients, topic);

            printf("Enter time allocated for ideas sending:\n");
            std::string timer;
            getline(std::cin, timer);
            timer = "STM:" + timer;
            sendOneMessage(clients, timer);

            sendOneMessage(clients, message);
            printf("Sending session started successfully.\n"
                   "Enter \"ES\" to end the sending session \n"
                   "and move to the voting session.\n");

            DWORD  allAMThreadID;
            allAMThread = CreateThread(
                NULL,
                0,
                checkAllAM,
                &clients,
                0,
                &allAMThreadID
                );
            continue;
        }

        WaitForSingleObject(mutexSendMsg, INFINITE);
        sendMessageQueue.push(message);
        ReleaseMutex(mutexSendMsg);
    }

    return exitThreadCode;
}

int getUID(int* UID) {

    WaitForSingleObject(mutexUI, INFINITE);
    int tempUID = ++(*UID);
    ReleaseMutex(mutexUI);

    return tempUID;
}

DWORD WINAPI rankIdeas(LPVOID param) {
    while (isRanking) {
        if (isVoted) {
            WaitForSingleObject(mutexIdeas, INFINITY);
            std::sort(ideaVector.begin(), ideaVector.end(), [](const Idea& a, const Idea& b) {
                return a.cntVoice > b.cntVoice;
            });
            ReleaseMutex(mutexIdeas);
        }
        Sleep(RERANK_TIME);
    }
    return 0;
}

DWORD WINAPI receiveMessages(LPVOID param) {
    Client* client = (Client*)param;

    char recvBuf[DEFAULT_BUFLEN];
    int recvBufLen = DEFAULT_BUFLEN;

    int iResult;
    int exitCode = 0;
    while (true) {

        iResult = recv(client->clientSocket, recvBuf, recvBufLen, 0);

        if (iResult > 0) {
            recvBuf[iResult] = '\0';

            std::string message(recvBuf);
            if (message == "AM") {
                WaitForSingleObject(mutexClients, INFINITE);
                for (int i = 0; i < clients.size(); i++) {
                    if (clients[i].clientUID == client->clientUID) {
                        clients[i].isAM = true;
                        break;
                    }
                }
                ReleaseMutex(mutexClients);
                continue;
            }

            WaitForSingleObject(mutexRecvMsg, INFINITE);
            ExtMessage msg = { client->clientUID, "" };
            strncpy_s(msg.message, iResult + 1, recvBuf, iResult);
            revcMessageQueue.push(msg);
            ReleaseMutex(mutexRecvMsg);

        } else if (iResult == 0) {

            printf("Connection successfully closed by client #%d\n", client->clientUID);
            exitCode = EXIT_CODE_RECV;
            break;
        } else {
            printf("recv from client #%d failed with error code: %d\n", client->clientUID, WSAGetLastError());
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

bool allAM(std::vector<Client>& clients) {
    bool isAllAM = true;
    WaitForSingleObject(mutexClients, INFINITE);
    for (int i = 0; i < clients.size(); i++) {
        if (clients[i].isAM == false) {
            isAllAM = false;
            break;
        }
    }
    ReleaseMutex(mutexClients);

    return isAllAM;
}
void nonAM(std::vector<Client>& clients) {

    WaitForSingleObject(mutexClients, INFINITE);
    for (int i = 0; i < clients.size(); i++) {
        clients[i].isAM = false;
    }
    ReleaseMutex(mutexClients);

    return;
}

int openListen() {

    int iResult = 0;
    int exitCode = 0;

    do {
        listenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
        if (listenSocket == INVALID_SOCKET) {
            printf("socket failed with error: %ld\n", WSAGetLastError());
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
    } while (false);

    return exitCode;
}

void closeListen(HANDLE& ListenThread, SOCKET& listenSocket) {
    TerminateThread(ListenThread, 0);
    CloseHandle(ListenThread);
    shutdown(listenSocket, SD_BOTH);
    closesocket(listenSocket);
    listenSocket = INVALID_SOCKET;
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
                printf("Connection with client #%d successfully terminated by server\n", client.clientUID);
            }
        } else {
            printf("Client #%d already has leaved session", client.clientUID);
        }
    } else {
        printf("GetExitCodeThread client #%d failed with error code: %d\n", client.clientUID, GetLastError());
    }
    TerminateThread(client.threadHandle, 0);
    delFromVector(clients,i);

    return;
}

void closeAllReceive(std::vector<Client>& clients, HANDLE& mutexClients) {
    printf("Closing connection with all clients...\n");
    WaitForSingleObject(mutexClients, INFINITE);
    for (int i = 0; i < clients.size(); i++) {
        closeOneReceive(clients, i);
        i--;
    }
    ReleaseMutex(mutexClients);
}

void delFromVector(std::vector<Client>& clients, int i) {
    CloseHandle(clients[i].threadHandle);

    shutdown(clients[i].clientSocket, SD_BOTH);
    closesocket(clients[i].clientSocket);

    printf("Client #%d deleted from vector\n", clients[i].clientUID);
    clients.erase(clients.begin() + i);
}

void closeClientWithUID(std::vector<Client>& clients, int UID) {
    bool isFound = false;
    WaitForSingleObject(mutexClients, INFINITY);
    for (int i = 0; i < clients.size(); i++) {
        if (clients[i].clientUID == UID) {
            isFound = true;
            closeOneReceive(clients, i);
            break;
        }
    }
    ReleaseMutex(mutexClients);
    if (!isFound) {
        printf("Unknown UID of user\n");
    }
}

void deleteIdea(int TID) {
    WaitForSingleObject(mutexIdeas, INFINITY);
    ideaVector.erase(
        std::remove_if(ideaVector.begin(), ideaVector.end(), [TID](const Idea& idea) {
            return idea.ideaTID == TID;
        }),
        ideaVector.end()
        );
    printf("Idea with TID: %d was sucessfully deleted\n", TID);
    ReleaseMutex(mutexIdeas);
}

void sendOneMessage(std::vector<Client>& clients, std::string message) {
    int iResult;
    DWORD exitCodeThread = 0;

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
            printf("GetExitCodeThread client #%d failed with error code: %d\n", clients[i].clientUID, GetLastError());
        }

        if (!isContinue) {
            TerminateThread(clients[i].threadHandle, 0);
            delFromVector(clients, i);
            i--;
        }
    }
    ReleaseMutex(mutexClients);
}

DWORD WINAPI sendMessages(LPVOID param) {
    std::vector<Client>* clients = (std::vector<Client>*)param;
    std::string message;
    int iResult;

    DWORD exitCode = 0;
    DWORD exitCodeThread = 0;

    while (true) {
        while (true) {
            if (!sendMessageQueue.empty()) break;
            Sleep(SLEEP_TIME);
        }
        WaitForSingleObject(mutexSendMsg, INFINITE);
        message = sendMessageQueue.front();
        sendMessageQueue.pop();
        ReleaseMutex(mutexSendMsg);

        if (message == "EXT") break;
        if (message == "CLN") {
            closeListen(ListenThread, listenSocket);

        } else if (message == "DCL") {
            printf("Enter UID of client to delete: ");
            int UID;
            scanf_s("%d", &UID);
            closeClientWithUID(*clients, UID);

        } else if (message == "SS") {
            //closeListen(ListenThread, listenSocket);

            //printf("Enter topic of discussion:\n");
            //std::string topic;
            //getline(std::cin, topic);
            //topic = "STP:" + topic;
            //sendOneMessage(*clients, topic);

            //printf("Enter time allocated for ideas sending:\n");
            //std::string timer;
            //getline(std::cin, timer);
            //timer = "STM:" + timer;
            //sendOneMessage(*clients, timer);

            //sendOneMessage(*clients, message);
            //printf("Sending session started successfully.\n"
            //       "Enter \"ES\" to end the sending session \n"
            //       "and move to the voting session.\n");

            //DWORD  allAMThreadID;
            //allAMThread = CreateThread(
            //    NULL,
            //    0,
            //    checkAllAM,
            //    clients,
            //    0,
            //    &allAMThreadID
            //);

        } else if (message == "DID") {
            printf("Enter TID of idea to delete: ");
            int TID;
            scanf_s("%d", &TID);
            deleteIdea(TID);

        } else if (message == "ES") {

            DWORD exitCodeAllAMThread = 0;
            GetExitCodeThread(allAMThread, &exitCodeAllAMThread);
            if (exitCodeAllAMThread == STILL_ACTIVE) {
                TerminateThread(allAMThread, 0);
            }

            printf("The sending session is complete.\n"
                   "Waiting to receive all customer messages...\n");
            sendOneMessage(*clients, "ES");

            while (true) {
                if (allAM(*clients) || timerOut) break;
                Sleep(500);
            }
            nonAM(*clients);

            printf("All user ideas successfully received.\n"
                   "Sending ideas list to clients...\n");

            WaitForSingleObject(mutexIdeas, INFINITY);
            for (int i = 0; i < ideaVector.size(); i++) {

                std::string idea;
                idea = "TGH:" + std::to_string(ideaVector[i].ideaTID);
                idea += " " + std::string(ideaVector[i].message.message);
                std::cout << idea << "\n";

                sendOneMessage(*clients, idea);
                Sleep(50);

            }
            ReleaseMutex(mutexIdeas);

            printf("Ideas list successfully sent.\n");

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
            printf("SV\n");
            sendOneMessage(*clients, "SV");
            printf("Voting session successfully started.\n"
                   "Waiting for clients voices...\n\n"
                   "Enter \"EV\" to end the voting session \n"
                   "and move to the results of session.\n");

            while (true) {
                if (allAM(*clients) || timerOut) break;
                Sleep(500);
            }
            nonAM(*clients);

            WaitForSingleObject(mutexSendMsg, INFINITE);
            sendMessageQueue.push("EV");
            ReleaseMutex(mutexSendMsg);

        } else if (message == "EV") {
            printf("Voting session ended.\n"
                   "Sending results to clients...\n");
            sendOneMessage(*clients, "EV");

            Sleep(RERANK_TIME);
            isRanking = false;

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

                std::cout << idea << "\n";
                sendOneMessage(*clients, idea);
            }
            Sleep(100);
            printf("Result successfully send.\n"
                   "Ending the current session...\n");

            sendOneMessage(*clients, "TS");
            closeAllReceive(*clients, mutexClients);
            printf("TS\n");

            printf("Current session successfully ended.\n"
                   "Enter \"RS\" to start new session.\n");

        } else if (message == "RS") {
            // sendOneMessage(*clients, "RS");
            printf("Trying to start new session...\n");
            ideaVector.clear();
            clients->clear();
            TID = 0;
            UID = 0;
            isRanking = false;
            iResult = openListen();
            if (!iResult) {
                printf("New session started successfully.\n"
                       "Waiting clients to connect...\n\n"
                       "Enter \"SS\" to start sending session.\n");
            } else {
                printf("Error while starting new session.\n");
            }
        }
    }

    closeListen(ListenThread, listenSocket);
    closeAllReceive(*clients, mutexClients);

    return exitCode;
}



// int __cdecl main1(void) {

//     // int iResult = 1;
//     // do {
//     //     mutexUI = CreateMutex(NULL, FALSE, NULL);
//     //     if (mutexUI == NULL) break;

//     //     mutexClients = CreateMutex(NULL, FALSE, NULL);
//     //     if (mutexClients == NULL) break;

//     //     mutexRecvMsg = CreateMutex(NULL, FALSE, NULL);
//     //     if (mutexRecvMsg == NULL) break;

//     //     mutexSendMsg = CreateMutex(NULL, FALSE, NULL);
//     //     if (mutexSendMsg == NULL) break;

//     //     mutexIdeas = CreateMutex(NULL, FALSE, NULL);
//     //     if (mutexIdeas == NULL) break;

//     //     iResult = 0;
//     // } while (false);

//     // if (iResult) {
//     //     printf("CreateMutex failed with error: %d\n", GetLastError());
//     //     return 1;
//     // }

//     // WSADATA wsaData;


//     // struct addrinfo hints;

//     // char recvBuf[DEFAULT_BUFLEN];
//     // int  recvBufLen = DEFAULT_BUFLEN;

//     // // Initialize Winsock
//     // iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
//     // if (iResult != 0) {
//     //     printf("WSAStartup failed with error: %d\n", iResult);
//     //     return 1;
//     // }

//     // ZeroMemory(&hints, sizeof(hints));
//     // hints.ai_family = AF_INET;
//     // hints.ai_socktype = SOCK_STREAM;
//     // hints.ai_protocol = IPPROTO_TCP;
//     // hints.ai_flags = AI_PASSIVE;

//     // // Resolve the server address and port
//     // iResult = getaddrinfo(NULL, DEFAULT_PORT, &hints, &result);
//     // if (iResult != 0) {
//     //     printf("getaddrinfo failed with error: %d\n", iResult);
//     //     WSACleanup();
//     //     return 1;
//     // }

//     // printf("Enter \"RS\" to start:\n");

//     // DWORD  inputThreadID;
//     // HANDLE inputThread = CreateThread(
//     //     NULL,
//     //     0,
//     //     inputMessages,
//     //     NULL,
//     //     0,
//     //     &inputThreadID
//     //     );

//     // DWORD threadID_send;
//     // HANDLE sendThread = CreateThread(
//     //     NULL,
//     //     0,
//     //     sendMessages,
//     //     &clients,
//     //     0,
//     //     &threadID_send
//     //     );
//     // DWORD threadID_servent;
//     // HANDLE serventThread = CreateThread(
//     //     NULL,
//     //     0,
//     //     receiveServent,
//     //     &clients,
//     //     0,
//     //     &threadID_servent
//     //     );

//     // DWORD exitCode;

//     while (true) {
//         Sleep(RERANK_TIME);
//     }

//     // WSACleanup();
//     // CloseHandle(mutexUI);
//     // CloseHandle(mutexClients);
//     // CloseHandle(mutexRecvMsg);
//     // CloseHandle(mutexSendMsg);
//     // CloseHandle(mutexIdeas);

//     printf("\nEND\n");

//     return 0;
// }

