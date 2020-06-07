#include "server_Acceptor.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <utility>
#include "common_OSError.h"

Acceptor::Acceptor(const char* port, NumberList&& numbers): 
                                                socket(Socket()), 
                                                numbers(numbers),
                                                continueExecution(false){
    this->socket.bindAndListen(port);
}

void Acceptor::joinClientHandlers(){
    std::vector<ClientHandler*> tmp;
    std::vector<ClientHandler*>::iterator iter = clients.begin();
    for (; iter != clients.end(); ++iter){
        if ((*iter)->isDead()){
            int result = (*iter)->joinAndGetResult();
            points(result);
            delete (*iter);
        } else{
            tmp.push_back(std::move(*iter));
        }
    }
    clients.swap(tmp);
}

void Acceptor::joinAndWaitClientHandlers(){
    std::vector<ClientHandler*>::iterator iter = clients.begin();
    for (; iter != clients.end(); ++iter){
        int result = (*iter)->joinAndGetResult();
        points(result);
        delete (*iter);
    }
}

void Acceptor::run(){
    continueExecution = true;
    while (continueExecution){
        try {
            Socket newSocket = socket.accept();
            ClientHandler* client = new ClientHandler(std::move(newSocket), 
                                                    points, 
                                                    numbers.getNumber());
            client->start();
            clients.push_back(client);
        }
        catch (OSError& e){}
        joinClientHandlers();
    }
    joinAndWaitClientHandlers();
    points.printStats();
}

void Acceptor::shutdown(){
    continueExecution = false;
    socket.close();
}

Acceptor::~Acceptor(){
    this->shutdown();
    if (this->joinable())
        this->join();
}
