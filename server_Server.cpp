#include <iostream>
#include "common_OSError.h"
#include "server_Server.h"
#include <iostream>

void Server::run(){
    acceptor.start();
    std::string input;
    while (std::getline(std::cin, input)){
        if (input == "q")
            break;
    }
    acceptor.shutdown();
    acceptor.join();
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
