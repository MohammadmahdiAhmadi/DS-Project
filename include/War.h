#ifndef WAR_H
#define WAR_H

#include <iostream>
using namespace std;
#include <cmath>

#define SA 2  //SpeedOfArmy

#include "Graph.h"
#include "Castle.h"
#include "StackLL.h"
#include "QueueLL.h"
#include "Soldier.h"

class War
{
    public:
        War(Graph* g, vector<Castle*> c, int e, int castleId);
        virtual ~War();


    private:
        int CastleId;
        int E;
        Graph* G;
        vector<Castle*> C;

        vector<queue<int>> Q;
        int Time;


        void queuePreparation();
        void checkTime();
        void oneStepAttack(int i);
};

#endif // WAR_H
