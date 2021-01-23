#include "Castle.h"

Castle::Castle(int id)
{
    this->id = id;
    this->army = 0;
    //ctor
}

Castle::~Castle()
{
    //dtor
}


void Castle::setArmy(int n){
    this->army = n;
}

void Castle::showNeighbors(int** matris, int e){
    cout << "Neighbors of Castle " << this->id << ": " << endl;
    for(int i=0; i<e; i++){
        if(matris[id][i] != 0){
            cout << "Caslte " << i << "(" << matris[id][i] << " km)" << endl;
        }
    }
}
