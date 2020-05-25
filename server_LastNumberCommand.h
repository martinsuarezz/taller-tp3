#ifndef LASTNUMBERCOMMAND_H
#define LASTNUMBERCOMMAND_H
#include "server_Command.h"
#include <string>
#include "server_ClientHandler.h"

class LastNumberCommand: public Command{
    private:

    public:
        LastNumberCommand(ClientHandler& client, std::vector<char>& command): 
                                                Command(client, command) {};
        std::string operator()();
};

#endif
