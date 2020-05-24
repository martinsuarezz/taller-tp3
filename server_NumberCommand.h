#ifndef NUMBERCOMMAND_H
#define NUMBERCOMMAND_H
#include "server_Command.h"
#include <string>
#include "server_ClientHandler.h"

class NumberCommand: public Command{
    private:

    public:
        NumberCommand(ClientHandler& client, std::vector<char> command): 
                                                Command(client, command) {};
        std::string operator()();
        //~NumberCommand();
};

#endif
