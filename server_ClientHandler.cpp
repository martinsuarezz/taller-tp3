#include "server_ClientHandler.h"
#include <string.h>
#include <arpa/inet.h>
#include <iostream>
#include "common_OSError.h"
#define MAX_TRIES 10

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
    try{
        int tries = 0;
        while (continueExecution && tries < MAX_TRIES){
            std::vector<char> commandLine;
            socket.receive(commandLine, 1);
            if (commandLine[0] == 'n'){
                socket.receive(commandLine, 2);
                tries++;
                if (tries == MAX_TRIES)
                    commandLine[0] = 'l';
            }
        Command* command = Command::getCommand(commandLine, *this);
        std::string commandString = command->operator()();
        socket.send(encodeCommand(commandString));
        delete command;
        }
        continueExecution = false;
    }
    catch(OSError& e){
        std::cerr << e.what() << std::endl;
    }
    catch(...){
        std::cerr << "Unespecified error" << std::endl;
    }
    
}

int ClientHandler::getNumberToGuess(){
    return numberToGuess;
}

void ClientHandler::setLose(){
    continueExecution = false;
    result = -1;
}

void ClientHandler::setVictory(){
    continueExecution = false;
    result = 1;
}

bool ClientHandler::isDead(){
    return !continueExecution;
}

int ClientHandler::joinAndGetResult(){
    this->join();
    return result;
}
