#include "server_Acceptor.h"
#include <vector>
#include <iostream>

Acceptor::Acceptor(const char* port, NumberList&& numbers): 
                                                socket(Socket()), 
                                                numbers(numbers),
                                                continueExecution(true){
    this->socket.bindAndListen(port);
}

void Acceptor::run(){
    Socket newSocket;
    socket.accept(newSocket);
    while (continueExecution){
        std::vector<char> text;
        newSocket.receive(text, 3);
        std::cout << text.data() << std::endl;
    }
}