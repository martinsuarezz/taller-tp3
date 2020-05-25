#ifndef CLIENT_H
#define CLIENT_H
#include "client_Communicator.h"

class Client{
    private:
        Communicator communicator;

    public:
        Client(const char* hostname, const char* port): 
                                communicator(Communicator(hostname, port)){}

        // Ejecuta el cliente.
        void run();
};

#endif
