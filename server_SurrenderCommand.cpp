#include "server_Command.h"
#include <string>
#include "server_SurrenderCommand.h"

std::string SurrenderCommand::operator()(){
    client.setLose();
    return std::move(std::string("Perdiste"));
}
