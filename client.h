#ifndef CLIENT_H
#define CLIENT_H

#include <arpa/inet.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

class Client
{
public:
    Client(std::string SERVER_NAME, int PORT);
};

#endif // CLIENT_H
