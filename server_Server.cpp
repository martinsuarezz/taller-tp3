#include <iostream>
#include "common_OSError.h"
#include "server_Server.h"

void Server::run(){
    for (int i = 0; i<20; i++)
        std::cout << numbers.getNumber() << std::endl;
}

int main(int argc, char* argv[]){
    if (argc != 3){
        std::cerr << "Error: argumentos invalidos." << std::endl;
        return 1;
    }

    try{
        Server server = Server(argv[1], argv[2]);
        server.run();
    }
    catch (OSError& error){
        std::cerr << error.what() << std::endl;
        return 1;
    }
    catch(...){
        std::cerr << "Unespecified error" << std::endl;
        return 1;
    }

    return 0;
} 
