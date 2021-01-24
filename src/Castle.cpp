#include "Castle.h"

Castle::Castle(int id, int armySize)
{
    this->id = id;
    this->armySize = armySize;
    //ctor
}

Castle::~Castle()
{
    //dtor
}


void Castle::showNeighbors(int** matris, int e){
    cout << "Neighbors of Castle " << this->id << ": " << endl;
    for(int i=0; i<e; i++){
        if(matris[id][i] != 0){
            cout << "Caslte " << i << "(" << matris[id][i] << " km)" << endl;
        }
    }
}

void Castle::setArmyTree(){
    for(int i=0; i<armySize; i++){
        this->armyTree.add(rand() % 80 + 20);//20-100 Power
    }
    armyTree.pre();
    cout << endl;
}
