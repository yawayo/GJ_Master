#include "socketclass.h"

SocketClass::SocketClass()
{

}

SocketClass::~SocketClass()
{

}

bool SocketClass::Open(int n_Port, int Baudrate)
{
    WSADATA wsaData;
    int iniResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (iniResult != 0)
    {
        qDebug() << "Can't Initialize winsock! Quitiing";
        return -1;
    }
}

bool SocketClass::Close()
{

}

bool SocketClass::writeData(char *buffer, size_t size)
{

}

bool SocketClass::readData(char *buffer, size_t limit)
{

}

bool SocketClass::isOpened()
{

}
