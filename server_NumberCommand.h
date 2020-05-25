#ifndef NUMBERCOMMAND_H
#define NUMBERCOMMAND_H
#include <string>
#include <vector>
#include "server_Command.h"
#include "server_ClientHandler.h"

class NumberCommand: public Command{
    public:
        NumberCommand(ClientHandler& client, std::vector<char>& command): 
                                                Command(client, command) {}
        std::string operator()();
};

#endif
