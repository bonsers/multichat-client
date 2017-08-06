#include "client.h"

Client::Client(std::string SERVER_NAME, int PORT)
{
    struct sockaddr_in serverAddress;
    memset(&serverAddress, 0, sizeof(serverAddress));
    serverAddress.sin_family = AF_INET;

    inet_pton(AF_INET, SERVER_NAME.c_str(), &serverAddress.sin_addr);

    serverAddress.sin_port = htons(PORT);

    int sock;
    if ((sock = socket(PF_INET, SOCK_STREAM, 0)) < 0)
    {
        std::cout << "Error: Could not create socket" << std::endl;
        //return 1;
    }

    if (connect(sock, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0)
    {
        std::cout << "Error: Could not connect to server" << std::endl;
        //return 1;
    }
    std::cout << "~~ Connected to " << inet_ntoa(serverAddress.sin_addr) << " on port " << PORT << std::endl;

    while (1)
    {
        std::string str;
        getline(std::cin, str);
        //std::cin >> str;

        send(sock, str.c_str(), strlen(str.c_str()), 0);
        str = "";
    }

    close(sock);
}
