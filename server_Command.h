#ifndef COMMAND_H
#define COMMAND_H
#include <string>
#include <vector>
#include "server_ClientHandler.h"

class ClientHandler;

class Command{
    protected:
        ClientHandler& client;
        std::vector<char>& command;

    public:
        Command(ClientHandler& client, std::vector<char>& command):
                                                        client(client),
                                                        command(command){};
        static Command* getCommand(std::vector<char> command, 
                                    ClientHandler& client);
        virtual std::string operator()() = 0;
        virtual ~Command();
};

#endif
