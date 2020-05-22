#include "client_Client.h"
#include <iostream>
#include <string>
#include "common_OSError.h"

void Client::run(){
    while (this->communicator.isRunning()){
        std::string command;
        std::getline(std::cin, command);
        std::cout << this->communicator.send(command) << std::endl;
    }
}

int main(int argc, char* argv[]){
    if (argc != 3){
        std::cout << "Error: argumentos invalidos." << std::endl;
        return 0;
    }

    try{
        Client client = Client(argv[1], argv[2]);
        client.run();
    }
    catch (OSError& error){
        std::cerr << error.what() << std::endl;
    }
    catch(...){
        std::cerr << "Unespecified error" << std::endl;
    }

    return 0;
}