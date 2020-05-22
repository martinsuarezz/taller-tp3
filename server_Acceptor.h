#ifndef ACCEPTOR_H
#define ACCEPTOR_H
#include "common_Socket.h"

class Acceptor{
    private:
        Socket socket;

    public:
        Acceptor(const char* port): socket(Socket()){};
};

#endif
