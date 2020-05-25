#include "client_Communicator.h"
#include <string>
#include <string.h>
#include <vector>
#include <arpa/inet.h>
#include <iostream>

static uint32_t vectorToUint32(std::vector<char>& vector){
    char* charNumber = vector.data();
    uint32_t number;
    memcpy(&number, charNumber, 4);
    return ntohl(number);
}

Communicator::Communicator(const char* hostname, const char* port){
    this->socket.connect(hostname, port);
}

std::string Communicator::send(std::string command){
    std::string formatedAnswer;
    Encoder encoder;
    std::vector<char> encoded = encoder.encode(command);
    if (encoded.empty()){
        formatedAnswer = "Error: comando inválido. "
                        "Escriba AYUDA para obtener ayuda";
    } else{
        std::vector<char> answer;
        std::vector<char> answerSize;
        socket.send(encoded);
        socket.receive(answerSize, 4);
        socket.receive(answer, vectorToUint32(answerSize));
        formatedAnswer = std::string(answer.data(), answer.size());
    }
    
    return formatedAnswer;
}

bool Communicator::isRunning(){
    return true;
}
