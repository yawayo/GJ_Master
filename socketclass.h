#ifndef SOCKETCLASS_H
#define SOCKETCLASS_H

#include <stdio.h>

#include <sstream>
#include <thread>

#include <winsock2.h>
#pragma comment(lib, "ws2_32")

#include <QDebug>

class SocketClass
{
public:
    SocketClass();
    ~SocketClass();

    bool Open(char* IP, int Port);
    bool Close(void);
    bool writeData(char *buffer, size_t size);
    bool readData(char *buffer, size_t limit);
    bool isOpened(void);
};

#endif // SOCKETCLASS_H
