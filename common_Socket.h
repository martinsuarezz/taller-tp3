#ifndef SOCKET_H
#define SOCKET_H
#include <vector>

class Socket{
    private:
        int socketfd;

    public:
        Socket(): socketfd(-1){};

        // Cambia el file descriptor del socket
        void set(int fd);

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

        // Acepta una conexión entrante y guarda el fd del socket
        // en el socket recibido.
        void accept(Socket& acceptedSocket);

        // Prohibo la copia de sockets
        Socket(const Socket&) = delete;
        Socket& operator=(const Socket&) = delete;

        // Permito el pasaje por movimiento;
        Socket(Socket&&) = default;
        ~Socket();
};

#endif
