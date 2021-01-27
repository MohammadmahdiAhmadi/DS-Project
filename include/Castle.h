#ifndef CASTLE_H
#define CASTLE_H

#include <iostream>
using namespace std;

#include "Graph.h"
#include "Avl.h"
#include "StackLL.h"


class Castle
{
    public:
        Castle(int id, int armySize);
        virtual ~Castle();

        void showNeighbors(int** matris, int e, int* army);
        void setArmyTree();
        StackLL<int> alvToQueue();
        void avlPre();
        int getId();
        int getArmySize();
        int* getDistributingSoldiersList();
        void distributingSoldiers(int* listOfCastlesArmys, int** matris, int e);


    private:
        int id;
        int armySize;
        Avl armyTree;
        int* distributingSoldiersList;

        vector<int> conqueredCastles;
        int conqueredBy;

};


#endif // CASTLE_H
