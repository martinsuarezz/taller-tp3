#include <string>
#include <utility>
#include "server_SurrenderCommand.h"
#include "server_Command.h"

std::string SurrenderCommand::operator()(){
    client.setLose();
    return std::move(std::string("Perdiste"));
}
