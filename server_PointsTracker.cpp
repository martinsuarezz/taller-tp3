#include "server_PointsTracker.h"
#include <iostream>

void PointsTracker::addWinner(){
    winners++;
}

void PointsTracker::addLoser(){
    losers++;
}

void PointsTracker::printStats(){
    std::cout << "Estadísticas:\n\tGanadores: " << this->winners;
    std::cout << "\n\tPerdedores: " << this->losers << "\n" << std::endl;
}

void PointsTracker::operator()(int result){
    if (result == 1)
        this->addWinner();
    if (result == -1)
        this->addLoser();
}