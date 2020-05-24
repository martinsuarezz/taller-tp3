#ifndef SERVER_H
#define SERVER_H
#include "server_NumberList.h"
#include "server_Acceptor.h"

class Server{
    private:
        NumberList numbers;
        Acceptor acceptor;

    public:
        Server(const char* port, const char* numbersFile):
            numbers(NumberList(numbersFile)), 
            acceptor(Acceptor(port, std::move(numbers))){};

        // Ejecuta el servidor.
        void run();
};

#endif 

