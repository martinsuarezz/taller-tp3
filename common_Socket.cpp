#define _POSIX_C_SOURCE 200112L

#include "common_Socket.h"
#include <sys/types.h>
#include <string.h>
#include <sys/socket.h>
#include <netdb.h>
#include <unistd.h>
#include "common_OSError.h"

void Socket::connect(const char* host, const char* service){
    struct addrinfo hints;
    int error, s;
    struct addrinfo *results, *rp;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = 0;

    if ((error = getaddrinfo(host, service, &hints, &results)) != 0)
        throw OSError("Could not establish connection");
    
    for (rp = results; rp != NULL; rp = rp->ai_next) {
        s = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        if (s == -1)
            continue;

        if (::connect(s, rp->ai_addr, rp->ai_addrlen) != -1){
            this->socketfd = s;
            freeaddrinfo(results);
            return;
        }
    }
    freeaddrinfo(results);
    throw OSError("Could not establish connection");
}

void Socket::send(const std::vector<char>& msg, size_t bytes){
    if (bytes == 0)
        bytes = msg.size();
    ssize_t status;
    ssize_t sent = 0;
    const char* message = msg.data();
    while (sent < (ssize_t) bytes){
        status = ::send(this->socketfd, (const void*) message, bytes, 0);
        if (status <= 0)
            throw OSError("Could not send information to server");
        sent += status;
    }
}

void Socket::receive(std::vector<char>& buffer, size_t bytes){
    ssize_t status;
    ssize_t received = 0;
    char character[1];
    while (received < (ssize_t) bytes){
        status = recv(this->socketfd, character, 1, 0);
        if (status <= 0)
            throw OSError("Could not receive more bytes from server");
        received += status;
        buffer.push_back(character[0]);
    }
}

Socket::~Socket(){
    if (this->socketfd != -1)
        ::close(this->socketfd);
}
