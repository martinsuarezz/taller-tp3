#ifndef ACCEPTOR_H
#define ACCEPTOR_H
#include "common_Socket.h"
#include "server_NumberList.h"

class Acceptor{
    private:
        Socket socket;
        NumberList numbers;
        bool continueExecution;

    public:
        Acceptor(const char* port, NumberList&& numbers);
        void run();
        void shutdown();
};

#endif
