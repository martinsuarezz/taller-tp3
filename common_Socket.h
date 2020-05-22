#ifndef SOCKET_H
#define SOCKET_H
#include <vector>

class Socket{
    private:
        int socketfd;

    public:
        Socket(): socketfd(-1) {};
        void connect(const char* host, const char* service);
        void send(const std::vector<char>& msg, size_t bytes = 0);
        void receive(std::vector<char>& buffer, size_t bytes);
        ~Socket();
};

#endif
