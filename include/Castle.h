#ifndef CASTLE_H
#define CASTLE_H

#include <iostream>
using namespace std;

#include "Graph.h"
#include "Avl.h"

class Castle
{
    public:
        Castle(int id, int armySize);
        virtual ~Castle();

        void showNeighbors(int** matris, int e, int* army);
        void setArmyTree();
        void alvToQueue();
        void avlPre();
        int getId();
        int getArmySize();
        int* distributingSoldiers(int* listOfNeighborsArmys, int e);


    private:
        int id;
        int armySize;
        Avl armyTree;

        vector<int> conqueredCastles;
        int conqueredBy;

};


#endif // CASTLE_H
