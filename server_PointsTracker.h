#ifndef POINTSTRACKER_H
#define POINTSTRACKER_H
#include <atomic>

class PointsTracker{
    private:
        int winners;
        int losers;

    public:
        PointsTracker(): winners(0), losers(0) {};
        void addWinner();
        void addLoser();
        void printStats();
        void operator()(int result);

};

#endif
