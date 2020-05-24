#include "server_ClientHandler.h"
#include <string.h>
#include <arpa/inet.h>

static void uint32ToVector(uint32_t number, std::vector<char>& vector){
    char charNumber[4];
    memcpy(charNumber, &number, 4);
    for (int i = 0; i < 4; i++)
        vector.push_back(charNumber[i]);
}

std::vector<char> ClientHandler::encodeCommand(std::string& command){
    std::vector<char> vector;
    uint32ToVector(htonl((uint32_t) command.size()), vector);
    std::copy(command.begin(), command.end(), std::back_inserter(vector));
    return vector;
}

void ClientHandler::run(){
    std::vector<char> commandLine;
    socket.receive(commandLine, 1);
    if (commandLine[0] == 'n')
        socket.receive(commandLine, 2);
    Command* command = Command::getCommand(commandLine, *this);
    std::string commandString = command->operator()();
    socket.send(encodeCommand(commandString));
    delete command;
}
