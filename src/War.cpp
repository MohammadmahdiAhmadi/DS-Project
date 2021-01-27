#include "War.h"

War::War(Graph* g, vector<Castle*> c, int e, int castleId)
{
    this->G = g;
    this->C = c;
    this->E = e;
    this->CastleId = castleId;

    queuePreparation();

    //ctor
}

War::~War()
{
    //dtor
}

void War::queuePreparation(){
    StackLL<int> s = C[CastleId]->alvToQueue();
    StackLL<int> st = C[CastleId]->alvToQueue();

    int* queuesSize = C[CastleId]->getDistributingSoldiersList();

    for(int i=0; i<E; i++){
        queue<int> temp;
        Q.push_back(temp);
        if(G->getMatris()[CastleId][i] != 0){
            for(int j=0; j<queuesSize[i]; j++){
                Q[i].push(s.top());
                s.pop();
            }
        }
    }



    cout << "Queus are ready for attack: \n";

    for(int i=0; i<E; i++){

    if(G->getMatris()[CastleId][i] != 0){
        cout << "Queue for castle " << i << ":  ";
        for(int j=0; j<queuesSize[i]; j++){
            cout << st.top() << " ";
            st.pop();
        }
        cout << endl;
        }
    }







}




