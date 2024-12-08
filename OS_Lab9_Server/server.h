#ifndef SERVER_H
#define SERVER_H

#define _CRT_SECURE_NO_WARNINGS
#undef UNICODE

#define WIN32_LEAN_AND_MEAN

#include <windows.h>
#include <winsock2.h>
#include <ws2tcpip.h>

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
#include <thread>
#include <vector>
#include <mutex>
#include <algorithm>
#include <queue>


#pragma comment (lib, "Ws2_32.lib")

#define DEFAULT_BUFLEN 512
#define DEFAULT_NAMELEN 64
#define DEFAULT_PORT "27015"

#define STUTDOWN_ERROR -1
#define EXIT_CODE_RECV 0
#define EXIT_CODE_SEND 0
#define SEND_MESS_FAIL 1
#define RESV_MESS_FAIL 1

#define RERANK_TIME 1000
#define SLEEP_TIME 500

typedef struct clnt {
    char name[DEFAULT_NAMELEN];
    int clientUID;
    DWORD threadID;
    SOCKET clientSocket;
    HANDLE threadHandle;
    bool isAM;
    clnt() : clientUID(-1), threadID(0), clientSocket(INVALID_SOCKET),
        threadHandle(NULL), name("unknown"), isAM(false) { }
} Client;

std::vector<Client> clients;


typedef struct extMsg {
    int clientUID;
    char message[DEFAULT_BUFLEN];
} ExtMessage;

std::queue<ExtMessage> revcMessageQueue;
std::queue<std::string> sendMessageQueue;

typedef struct idea {
    int ideaTID;
    ExtMessage message;
    int cntVoice;
} Idea;

std::vector<Idea> ideaVector;

std::string sessionTopic;
int sessionTimeSec = 0;

std::string progStage = "DS";

int UID = 0;
int TID = 0;

HANDLE mutexUI = NULL;
HANDLE mutexClients = NULL;
HANDLE mutexRecvMsg = NULL;
HANDLE mutexSendMsg = NULL;
HANDLE mutexIdeas = NULL;

HANDLE allAMThread;
HANDLE ListenThread;
SOCKET listenSocket = INVALID_SOCKET;


int timerOut = false;

HANDLE RankThread;
bool isVoted = false;
bool isRanking = false;


struct addrinfo* result = NULL;

DWORD WINAPI rankIdeas(LPVOID param);

DWORD WINAPI sendMessages(LPVOID param);
DWORD WINAPI receiveMessages(LPVOID param);

DWORD WINAPI listenClients(LPVOID param);
DWORD WINAPI receiveServent(LPVOID param);

int getUID(int* UID);

bool allAM(std::vector<Client>& clients);
void nonAM(std::vector<Client>& clients);

int openListen();
void closeListen(HANDLE& ListenThread, SOCKET& listenSocket);

void closeOneReceive(std::vector<Client>& clients, int i);
void closeAllReceive(std::vector<Client>& clients, HANDLE& mutexClients);
void closeClientWithUID(std::vector<Client>& clients, int UID);
void delFromVector(std::vector<Client>& clients, int i);

void sendOneMessage(std::vector<Client>& clients, std::string message);

void deleteIdea(int TID);

// DWORD WINAPI inputMessages(LPVOID param);

DWORD WINAPI checkAllAM(LPVOID param);

#include "server.cpp"

#endif // SERVER_H
