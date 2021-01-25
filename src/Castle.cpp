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


void Castle::showNeighbors(int** matris, int e, int* army){
    cout << "Neighbors of Castle " << this->id << ": " << endl;
    for(int i=0; i<e; i++){
        if(matris[id][i] != 0){
            cout << "Caslte " << i << "(" << matris[id][i] << " km, " << army[i] << "-man army)" << endl;
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

void Castle::alvToQueue(){
    this->armyTree.reverseLevelOrder();
    return;
}

void Castle::avlPre(){
    this->armyTree.pre();
}

int Castle::getId(){
    return id;
}

int Castle::getArmySize(){
    return armySize;
}




