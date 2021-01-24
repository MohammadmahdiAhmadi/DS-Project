#ifndef CASTLE_H
#define CASTLE_H

#include "Graph.h"


class Castle
{
    public:
        Castle(int id);
        virtual ~Castle();

        void setArmy(int n);
        void showNeighbors(int** matris, int e);

    protected:

    private:
        int id;
        int army;


};


#endif // CASTLE_H
