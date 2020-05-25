#include "server_Command.h"
#include <string>
#include "server_NumberCommand.h"
#include <string.h>
#include <arpa/inet.h>
#include "server_Number.h"

// Convierte un array de 2 caracteres a entero
// El numero se presupone que está en big endian.
static int charToInt(char* charNumber){
    int16_t number;
    memcpy(&number, charNumber, 2);
    return (int) ntohs(number);
}

std::string NumberCommand::operator()(){
    Number serverNumber(client.getNumberToGuess());
    Number clientNumber(charToInt(command.data()+1));
    std::string answer;
    if (clientNumber.ammountDigits() != 3 || clientNumber.hasRepeatedDigits()){
        answer = "Número inválido. Debe ser de 3 cifras no repetidas";
        return answer;
    }
    if (serverNumber == clientNumber){
        client.setVictory();
        answer = "Ganaste";
        return answer;
    }

    int samePlaceDigits = serverNumber.ammountSameDigitsSamePlace(clientNumber);
    int diffPlaceDigits = serverNumber.ammountSameDigitsDiffPlace(clientNumber);
    if (samePlaceDigits + diffPlaceDigits == 0){
        answer = std::to_string(serverNumber.ammountDigits()) + " mal";
        return answer;
    }

    if (samePlaceDigits != 0)
        answer = std::to_string(samePlaceDigits) + " bien";
    if (diffPlaceDigits != 0){
        if (answer.size() != 0)
            answer += ", ";
        answer += std::to_string(diffPlaceDigits) + " regular";
    }
    return answer;
}
