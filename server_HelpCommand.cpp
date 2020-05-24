#include <string>
#include "server_HelpCommand.h"
#include "server_Command.h"

std::string HelpCommand::operator()(){
    return std::move(std::string("Comandos válidos:\n\tAYUDA: "
                                "despliega la lista de comandos válidos\n"
                                "\tRENDIRSE: pierde el juego automáticamente\n"
                                "\tXXX: Número de 3 cifras a ser enviado al "
                                "servidor para adivinar el número secreto"));
}
