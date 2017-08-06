#include <string>
#include "client.h"

int main()
{
    const std::string SERVER_NAME = "localhost";
    const int PORT = 8877;

    Client client(SERVER_NAME, PORT);

    return 0;
}
