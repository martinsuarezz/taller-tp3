#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H
#include "common_Socket.h"
#include "server_PointsTracker.h"
#include "server_Command.h"

class ClientHandler{
    private:
        Socket socket;
        PointsTracker& points;
        std::vector<char> encodeCommand(std::string& command);

    public:
        ClientHandler(Socket&& socket, PointsTracker& points):
                                            socket(std::move(socket)), 
                                            points(points) {};
        void run();
};

#endif
