#ifndef SURRENDERCOMMAND_H
#define SURRENDERCOMMAND_H
#include <string>
#include <vector>
#include "server_Command.h"
#include "server_ClientHandler.h"

class SurrenderCommand: public Command{
    public:
        SurrenderCommand(ClientHandler& client, std::vector<char>& command): 
                                                Command(client, command) {}
        std::string operator()();
};

#endif
