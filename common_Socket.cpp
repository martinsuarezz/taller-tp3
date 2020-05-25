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
        throw OSError("Could not establish connection", SHOW_ERR);
    
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
    throw OSError("Could not establish connection", SHOW_ERR);
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
            throw OSError("Could not send information to server", SHOW_ERR);
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
            throw OSError("Could not receive more bytes from server", SHOW_ERR);
        received += status;
        buffer.push_back(character[0]);
    }
}

void Socket::bindAndListen(const char* service){
    struct addrinfo hints;
    struct addrinfo *result, *rp;
    int sfd, s;

    memset(&hints, 0, sizeof(struct addrinfo));
    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    s = getaddrinfo(NULL, service, &hints, &result);
    if (s != 0) 
        throw OSError("Failed listening to port", SHOW_ERR, service);
    
    for (rp = result; rp != NULL; rp = rp->ai_next) {
        sfd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
        int val = 1;
        setsockopt(sfd, SOL_SOCKET, SO_REUSEADDR, &val, sizeof(val));
        if (sfd == -1)
            continue;

        if (bind(sfd, rp->ai_addr, rp->ai_addrlen) == 0 && listen(sfd, 1) == 0)
            break;                  /* Success */

        ::close(sfd);
    }

    if (rp == NULL)
        throw OSError("Failed listening to port", SHOW_ERR, service);
    
    freeaddrinfo(result);
    this->socketfd = sfd;
}

Socket Socket::accept(){
    int newSocketfd;
    if ((newSocketfd = ::accept(this->socketfd, NULL, NULL)) == -1)
        throw OSError("Failed to accept a conection", SHOW_ERR);
    
    return std::move(Socket(newSocketfd));
}

void Socket::close(){
    ::shutdown(this->socketfd, SHUT_RDWR);
    ::close(this->socketfd);
    this->socketfd = -1;
}

Socket::Socket(Socket&& other){
    this->socketfd = other.socketfd;
    other.socketfd = -1;
}

Socket::~Socket(){
    if (this->socketfd != -1)
        ::close(this->socketfd);
}
