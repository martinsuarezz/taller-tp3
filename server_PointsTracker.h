#ifndef POINTSTRACKER_H
#define POINTSTRACKER_H
#include <atomic>

class PointsTracker{
    private:
        int winners;
        int losers;
        void addWinner();
        void addLoser();

    public:
        PointsTracker(): winners(0), losers(0) {}
        void printStats();
        void operator()(int result);
};

#endif
