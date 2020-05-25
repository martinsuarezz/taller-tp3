#ifndef LASTNUMBERCOMMAND_H
#define LASTNUMBERCOMMAND_H
#include <string>
#include <vector>
#include "server_Command.h"
#include "server_ClientHandler.h"

class LastNumberCommand: public Command{
    public:
        LastNumberCommand(ClientHandler& client, std::vector<char>& command): 
                                                Command(client, command) {}
        std::string operator()();
};

#endif
