#ifndef SOCKETCLASS_H
#define SOCKETCLASS_H

#include <stdio.h>

#include <sstream>
#include <thread>

#include <winsock2.h>
#pragma comment(lib, "ws2_32")

#include <QDebug>

#define STX                     0xFFFFFFFE
#define ETX                     0xFF

#define PD_INOUT                0x01
#define PD_INDEX                0x02
#define DANGER_LEVEL            0x04
#define CHECK_CONNECTION        0x05

#define PD_INOUT_ACK            0x11
#define DANGER_LEVEL_ACK        0x14
#define CHECK_CONNECTION_ACK    0x15

#define IN                      0x02
#define OUT                     0x01

#define NACK                    0x30
#define ACK                     0x31

#define MAX_SLAVE_NUM 25
#define RESEND_TIME 3

class SocketClass
{
public:
    SocketClass();
    ~SocketClass();

    SOCKET sock;
    bool socketStatus;

    bool Open(char* IP, int Port);
    bool Close(void);
    bool writeData(char *buffer, size_t size);
    char readOneByte();
    bool isOpened(void);

};

#endif // SOCKETCLASS_H
