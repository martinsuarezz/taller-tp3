#ifndef COMMUNICATOR_H
#define COMMUNICATOR_H
#include <string>
#include "client_Encoder.h"
#include "common_Socket.h"

class Communicator{
    private:
        Socket socket;

    public:
        // Crea el comunicador. Se conecta a un servidor con
        // la dirección y puerto recibido.
        Communicator(const char* hostname, const char* port);

        // Envía al servidor el comando. Devuelve la respuesta
        // del servidor.
        std::string send(std::string command);

        // Devuelve si el comunicador sigue conectado con el
        // servidor.
        bool isRunning();
};

#endif
