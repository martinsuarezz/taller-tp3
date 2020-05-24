#include "server_Command.h"
#include <string>
#include "server_NumberCommand.h"

std::string NumberCommand::operator()(){
    return std::move(std::string("es un numero"));
}
