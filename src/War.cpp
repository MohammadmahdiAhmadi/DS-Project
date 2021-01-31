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
                if(distances[i] > 0){//to check distance
                    distances[i] -= SA;
                }
                else{
                    oneStepAttack(i);
                }
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

    //********************************************************//

    //I had problem in Fibonacci tree Delete() function
    //so we are currently using the AVL tree

    //********************************************************//

    vector<Node*> temp = C[i]->avlIn();

    for(int j=0; j<temp.size(); j++){//set CastleId
        temp[j]->CastleId = i;
    }

    vector<Node*> v = findSuitableSoldier(C[i]->attackerArmysIn, temp);
    /*
    for(int j=0; j<v.size(); j++){
        cout << v[j]->key << " for " << C[i]->attackerArmysIn.front() << ", ";
        C[i]->attackerArmysIn.pop();
    }
    */

    for(int j=0; j<IC; j++){//add attacker soldier to vector (with them castleId)
        Node* intToNode = new Node(C[i]->attackerArmysIn.front(), CastleId);
        temp.push_back(intToNode);

        C[i]->attackerArmysIn.pop();
    }


    //sort vector with new nodes Based on Node.key
    sort(temp.begin(), temp.end(), [](const Node* lhs, const Node* rhs) {
      return lhs->key < rhs->key;
        });

    //#TODO
    //add all of vector nodes in avl tree (fibonacci soon)
    Avl* Fibo = new Avl();
    for(int j=0; j<temp.size(); j++){
        Fibo->add(temp[j]->key, temp[j]->CastleId);
    }
    Fibo->in();
    vector<Node*> inVector = Fibo->inVector;
    for(int j=0; j<inVector.size(); j++){
        cout << inVector[j]->CastleId << " ";
    }
    cout << endl;

    //delete extra nodes

    //winer or loser???

    //dead stack, avl again, ...



}

vector<Node*> War::findSuitableSoldier(queue<int> qu, vector<Node*> temp){
    vector<Node*> v;


    for(int i=0; i<qu.size(); i++){
        int f = 100;//Or 80. (maximum diffrence)
        int flag = -1;
        for(int j=0; j<temp.size(); j++){
            if(abs(temp[j]->key - qu.front()) < f){
                //cout << abs(temp[j]->key - qu.front()) << " ";
                f = abs(temp[j]->key - qu.front());
                flag = j;
            }
        }
        v.push_back(temp[flag]);
        qu.push(qu.front());
        qu.pop();
    }

    return v;
}




