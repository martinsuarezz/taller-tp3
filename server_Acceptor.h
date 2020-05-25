#ifndef ACCEPTOR_H
#define ACCEPTOR_H
#include <vector>
#include "common_Socket.h"
#include "server_NumberList.h"
#include "server_ClientHandler.h"
#include "server_PointsTracker.h"
#include "server_Thread.h"

class Acceptor: public Thread{
    private:
        Socket socket;
        NumberList numbers;
        bool continueExecution;
        std::vector<ClientHandler*> clients;
        PointsTracker points;
        void joinClientHandlers();
        void joinAndWaitClientHandlers();

    public:
        Acceptor(const char* port, NumberList&& numbers);
        void run();
        void shutdown();
        Acceptor(Acceptor&&) = default;
};

#endif
