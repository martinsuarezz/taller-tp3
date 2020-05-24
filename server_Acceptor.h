#ifndef ACCEPTOR_H
#define ACCEPTOR_H
#include "common_Socket.h"
#include "server_NumberList.h"
#include "server_ClientHandler.h"
#include "server_PointsTracker.h"

class Acceptor{
    private:
        Socket socket;
        NumberList numbers;
        bool continueExecution;
        std::vector<ClientHandler> clients;
        PointsTracker points;

    public:
        Acceptor(const char* port, NumberList&& numbers);
        void run();
        void shutdown();
};

#endif
