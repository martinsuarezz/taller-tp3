#ifndef HELPCOMMAND_H
#define HELPCOMMAND_H
#include <string>
#include "server_Command.h"

class HelpCommand: public Command{
    public:
        HelpCommand(ClientHandler& client, std::vector<char>& command): 
                                                Command(client, command) {};
        std::string operator()();
};

#endif
