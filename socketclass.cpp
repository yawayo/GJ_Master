#include "socketclass.h"

SocketClass::SocketClass()
{
    socketStatus = false;
}

SocketClass::~SocketClass()
{
    socketStatus = false;
}

bool SocketClass::Open(char* IP, int Port)
{
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0)
    {
        return 1;
    }

    sock = socket(PF_INET, SOCK_STREAM, 0);

    SOCKADDR_IN addr;

    memset(&addr, 0, sizeof(addr));

    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = inet_addr(IP);
    addr.sin_port = htons(Port);

    if (connect(sock, (SOCKADDR*)&addr, sizeof(SOCKADDR_IN)) == SOCKET_ERROR)
    {
        qDebug() << "error";
        return false;
    }

    return true;
}
bool SocketClass::Close()
{
    closesocket(sock);
    WSACleanup();
}

bool SocketClass::writeData(char *buffer, size_t size)
{
    send(sock, buffer, size + 1, 0);
}

char SocketClass::readOneByte()
{
    char buf;

    if(recv(sock, &buf, sizeof(char), 0) != SOCKET_ERROR)
        return buf;

    return 0;
}

bool SocketClass::isOpened()
{
    return socketStatus;
}
