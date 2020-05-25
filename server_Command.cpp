#include "server_Command.h"
#include "server_HelpCommand.h"
#include "server_NumberCommand.h"
#include "server_SurrenderCommand.h"
#include "server_LastNumberCommand.h"
#include <vector>

Command* Command::getCommand(std::vector<char>& command, ClientHandler& client){
    if (command[0] == 'h')
        return new HelpCommand(client, command);
    else if (command[0] == 's')
        return new SurrenderCommand(client, command);
    else if (command[0] == 'n')
        return new NumberCommand(client, command);
    else if (command[0] == 'l')
        return new LastNumberCommand(client, command);
    return NULL;
}

Command::~Command() {}
