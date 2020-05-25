#ifndef SOCKET_H
#define SOCKET_H
#include <vector>
#include <stdlib.h>

class Socket{
    private:
        int socketfd;
        explicit Socket(int socketfd): socketfd(socketfd){}

    public:
        Socket(): socketfd(-1){}

        // Se conecta a la dirección y puerto especificados.
        // Se lanza una excepción si falla.
        void connect(const char* host, const char* service);

        // Envía la cantidad de bytes especificados del mensaje.
        // Si no se especifica la cantidad de bytes a enviar se
        // envía todo el mensaje.
        void send(const std::vector<char>& msg, size_t bytes = 0);

        // Recibe la cantidad de bytes especificada y los almacena
        // en el vector recibido por referencia.
        void receive(std::vector<char>& buffer, size_t bytes);

        // Escucha conexiones entrantes al puerto indicado.
        void bindAndListen(const char* service);

        // Cierra el socket y lo coloca en un estado inválido.
        void close();

        // Acepta una conexión entrante y guarda el fd del socket
        // en el socket recibido.
        Socket accept();

        // Permito el pasaje por movimiento;
        Socket(Socket&& other);

        // Prohibo la copia de sockets
        Socket(const Socket&) = delete;
        Socket& operator=(const Socket&) = delete;

        ~Socket();
};

#endif
