#include "socketclass.h"

SocketClass::SocketClass()
{

}

SocketClass::~SocketClass()
{

}

bool SocketClass::Open(char* IP, int Port)
{
//    WORD		wVersionRequested;
//    WSADATA		wsaData;
//    SOCKADDR_IN servAddr, cliAddr; //Socket address information
//    int			err;
//    int			bytesSent;
//    char        buf[50];

//    wVersionRequested = MAKEWORD(1, 1);
//    err = WSAStartup(wVersionRequested, &wsaData);

//    if (err != 0) {
//        qDebug() << "WSAStartup error " << WSAGetLastError();
//        WSACleanup();
//        return false;
//    }

//    servAddr.sin_family = AF_INET; // address family Internet
//    servAddr.sin_port = htons(Port); //Port to connect on
//    servAddr.sin_addr.s_addr = inet_addr(IP); //Target IP


//    SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //Create socket
//    if (s == INVALID_SOCKET)
//    {
//        qDebug() << "Socket error " << WSAGetLastError();
//        WSACleanup();
//        return false; //Couldn't create the socket
//    }

//    int x = bind(s, reinterpret_cast<SOCKADDR *>(&servAddr), sizeof(servAddr));
//    if (x == SOCKET_ERROR)
//    {
//        qDebug() << "Binding failed. Error code: " << WSAGetLastError();
//        WSACleanup();
//        return false; //Couldn't connect
//    }

//    qDebug() << "Waiting for client...";

//    listen(s, 5);
//    int xx = sizeof(cliAddr);
//    SOCKET s2 = accept(s, reinterpret_cast<SOCKADDR *>(&cliAddr), &xx);
//    qDebug() << "Connection established. New socket num is " << s2;

//    int iRand = 0;
//    int n = 0;
//    while (true)
//    {
//        n = recv(s2, buf, 50, 0);
//        if (n <= 0) { qDebug() << "Got nothing"; break; }
//        buf[n] = 0;
//        if (!strcmp(buf, "HELLO"))
//        {// Initial communication
//            iRand = 4;
//            auto sRand = std::to_string(iRand);
//            qDebug() << "Sending random number " << iRand << " to the client.";
//            bytesSent = send(s2, sRand.c_str(), sRand.length(), 0);

//            continue;
//        }
//        std::string sNum(buf);
//        try
//        {
//            iRand = stoi(sNum);
//            qDebug() << "Server got " << "\"" << iRand << "\"";
//            std::this_thread::sleep_for(std::chrono::seconds(1));
//            qDebug() << "Sending \"" << ++iRand << "\"" << " to client";
//            auto sRand = std::to_string(iRand);
//            bytesSent = send(s2, sRand.c_str(), sRand.length(), 0);
//        }
//        catch (const std::invalid_argument &ex)
//        {
//            qDebug() << "Invalid argument while converting string to number";
//            qDebug() << "Error: " << ex.what();
//            break;
//        }
//        catch (const std::out_of_range &ex)
//        {
//            qDebug() << "Invalid argument while converting string to number";
//            qDebug() << "Error: " << ex.what();
//            break;
//        }
//    }

//    closesocket(s);
//    WSACleanup();

    return 0;
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
