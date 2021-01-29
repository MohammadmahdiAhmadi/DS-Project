#include "War.h"

War::War(Graph* g, vector<Castle*> c, int e, int castleId)
{
    this->G = g;
    this->C = c;
    this->E = e;
    this->CastleId = castleId;
    Time = 0;

    queuePreparation();
    checkTime();

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

void War::checkTime(){
    int* distances = new int[E];
    for(int i=0; i<E; i++)
        distances[i] = G->getMatris()[CastleId][i];

    int check = 1;
    while(check){
        cout << "Enter 1 to go to the next step: ";
        cin >> check;
        if(check != 1)
            break;

        for(int i=0; i<E; i++){
            if(G->getMatris()[CastleId][i] != 0){//just neighbors
                //if(distances[i] > 0){//for check distance
                //    distances[i] - SA;
                //}
                //else{
                    oneStepAttack(i);
                //}
            }
        }



        Time ++;
    }

}

void War::oneStepAttack(int i){
    //Calculate input capacity
    int IC = ceil((float)Q[i].size() / (float)C[i]->getArmySize());

    for(int j=0; j<IC; j++){
        C[i]->attackerArmysIn.push(Q[i].front());
        Q[i].pop();
    }

    //Create Soldier class for each soldier and create fibonacci tree


}




