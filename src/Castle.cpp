#include "Castle.h"

Castle::Castle(int id, int armySize)
{
    this->id = id;
    this->armySize = armySize;

    this->conqueredBy = -1;
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

int* Castle::distributingSoldiers(int* listOfNeighborsArmys, int e){
    int allArmys = 0;
    for(int i=0; i<e; i++){
        if(listOfNeighborsArmys[i] != 0){
            allArmys += listOfNeighborsArmys[i];
        }
    }

    double Ratio = (float)this->getArmySize()/(float)allArmys;
    int allArmysNew = 0;

    for(int i=0; i<e; i++){
        if(listOfNeighborsArmys[i] != 0){
            float t = (float)listOfNeighborsArmys[i] * Ratio;
            listOfNeighborsArmys[i] = (int)t;

            allArmysNew += listOfNeighborsArmys[i];
        }
    }


    if(this->getArmySize() - allArmysNew >= 1){
        int flag = 0;
        int temp = 1000;

        //find smallest castle
        for(int i=0; i<e; i++){
            if(listOfNeighborsArmys[i] != 0 && listOfNeighborsArmys[i] < temp){
                temp = listOfNeighborsArmys[i];
                flag = i;
            }
        }

        listOfNeighborsArmys[flag] += this->getArmySize() - allArmysNew;
    }

    return listOfNeighborsArmys;
}


