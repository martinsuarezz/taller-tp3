#ifndef SERVER_H
#define SERVER_H
#include "server_NumberList.h"
#include "server_Acceptor.h"


class Server{
    private:
        Acceptor acceptor;
        NumberList numbers;

    public:
        Server(const char* port, const char* numbersFile):
            acceptor(Acceptor(port)), numbers(NumberList(numbersFile)){};

        // Ejecuta el servidor.
        void run();
};

#endif 

