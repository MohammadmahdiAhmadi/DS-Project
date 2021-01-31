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

StackLL<int> Castle::alvToQueue(){
    return this->armyTree.reverseLevelOrder();
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

int* Castle::getDistributingSoldiersList(){
    return distributingSoldiersList;
}

void Castle::distributingSoldiers(int* listOfCastlesArmys, int** matris, int e){
    int allArmys = 0;
    for(int i=0; i<e; i++){
        if(matris[id][i] != 0){
            allArmys += listOfCastlesArmys[i];
        }
    }

    double Ratio = (float)this->getArmySize()/(float)allArmys;
    int allArmysNew = 0;

    for(int i=0; i<e; i++){
        if(matris[id][i] != 0){
            float t = (float)listOfCastlesArmys[i] * Ratio;
            listOfCastlesArmys[i] = (int)t;

            allArmysNew += listOfCastlesArmys[i];
        }
    }


    if(this->getArmySize() - allArmysNew >= 1){
        int flag = 0;
        int temp = 1000;

        //find smallest castle
        for(int i=0; i<e; i++){
            if(matris[id][i] != 0 && listOfCastlesArmys[i] < temp){
                temp = listOfCastlesArmys[i];
                flag = i;
            }
        }

        listOfCastlesArmys[flag] += this->getArmySize() - allArmysNew;
    }

    distributingSoldiersList = listOfCastlesArmys;
    return;
}


vector<Node*> Castle::avlIn(){
    this->armyTree.in();
    return this->armyTree.inVector;
}


