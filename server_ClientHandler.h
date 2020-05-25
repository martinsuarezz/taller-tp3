#ifndef CLIENTHANDLER_H
#define CLIENTHANDLER_H
#include "common_Socket.h"
#include "server_PointsTracker.h"
#include "server_Command.h"
#include <stdbool.h>
#include "server_Thread.h"

class ClientHandler: public Thread{
    private:
        Socket socket;
        PointsTracker& points;
        int numberToGuess;
        bool continueExecution;
        int result;
        std::vector<char> encodeCommand(std::string& command);

    public:
        ClientHandler(Socket&& socket, PointsTracker& points, int number):
                                            socket(std::move(socket)), 
                                            points(points),
                                            numberToGuess(number),
                                            continueExecution(true),
                                            result(-1) {};
        void run();
        int getNumberToGuess();
        void setVictory();
        void setLose();
        bool isDead();
        int joinAndGetResult();
        ClientHandler(ClientHandler&&) = default;

        // Prohibo la copia de client handlers
        ClientHandler(const ClientHandler&) = delete;
        ClientHandler& operator=(const ClientHandler&) = delete;

};

#endif
