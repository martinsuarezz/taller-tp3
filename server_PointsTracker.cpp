#include "server_PointsTracker.h"
#include <iostream>

void PointsTracker::addWiner(){
    winners++;
}

void PointsTracker::addLoser(){
    losers++;
}

void PointsTracker::printStats(){
    std::cout << "Estadísticas:\n\tGanadores: " << this->winners;
    std::cout << "\n\tPerdedores: " << this->losers << "\n" << std::endl;
}
