#ifndef STARTGAME_H
#define STARTGAME_H

#include <iostream>
using namespace std;

#include "Graph.h"
#include "Castle.h"

class StartGame
{
    public:
        StartGame();
        virtual ~StartGame();

        void showTargetCastles();

    private:
        int CastleId;
        int E;
        Graph* G;
        vector<Castle*> C;

        void setGraph();
        void setCastles();
        void choiceCastle();
};

#endif // STARTGAME_H
