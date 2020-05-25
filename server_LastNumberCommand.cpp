#include "server_Command.h"
#include <string>
#include "server_LastNumberCommand.h"
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

std::string LastNumberCommand::operator()(){
    Number serverNumber(client.getNumberToGuess());
    Number clientNumber(charToInt(command.data()+1));
    std::string answer;
    if (serverNumber == clientNumber){
        answer = "Ganaste";
        client.setVictory();
    } else{
        answer = "Perdiste";
        client.setLose();
    }

    return answer;
}
