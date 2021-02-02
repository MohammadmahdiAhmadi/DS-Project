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


    //add attacker soldier to vector (with them castleId)
    for(int j=0; j<IC; j++){
        Node* intToNode = new Node(C[i]->attackerArmysIn.front(), CastleId);
        temp.push_back(intToNode);

        C[i]->attackerArmysIn.push( C[i]->attackerArmysIn.front());
        C[i]->attackerArmysIn.pop();
    }


    //sort vector with new nodes Based on Node.key
    sort(temp.begin(), temp.end(), [](const Node* lhs, const Node* rhs) {
      return lhs->key < rhs->key;
        });


    //add all of vector nodes in avl tree (fibonacci soon)
    Avl* Fibo = new Avl();
    for(int j=0; j<temp.size(); j++){
        Fibo->add(temp[j]->key, temp[j]->CastleId);
    }


    //delete extra nodes
    for(int j=0; j<temp.size(); j++){//traversal in all nodes of tree
        int flag = 1;
        for(int k=0; k<v.size(); k++){//traversal in all nodes that they want defence
            if(temp[j] == v[k] || temp[j]->CastleId == this->CastleId ){
                flag = 0;
                break;
            }
        }

        if(flag == 1)
            Fibo->del(temp[j]->key, temp[j]->CastleId);
    }
    //destroying extra memory (temp, ...)


    //winer or loser???
    //Fibo height, v(vector<Node*>) ,C[i]->attackerArmysIn(queue<int>)

    int height = -1;
    vector<int> winerCastleId;
    vector<int> attackerArmysInBACKUP;

    for(int j=0; j<v.size(); j++){
        height = Fibo->find(v[j]->key)->height;
        winerCastleId.push_back(i);

        if(Fibo->find( C[i]->attackerArmysIn.front() )->height > height){
            height = Fibo->find( C[i]->attackerArmysIn.front() )->height;
            winerCastleId[j] = this->CastleId;
        }

        else if(Fibo->find( C[i]->attackerArmysIn.front() )->height == height){
            if(C[i]->attackerArmysIn.front() > v[j]->key){
                winerCastleId[j] = this->CastleId;
            }

        }
        attackerArmysInBACKUP.push_back(C[i]->attackerArmysIn.front());
        C[i]->attackerArmysIn.pop();
    }


    //dead stack, avl again, ...
    for(int j=0; j<winerCastleId.size(); j++){
        if(winerCastleId[j] == i){//defencer soldier win
            C[CastleId]->deadStack.push(attackerArmysInBACKUP[j]);//dead stack...

        }
        else if(winerCastleId[j] == this->CastleId){//attacker soldier win
            C[i]->armyTree.del(v[j]->key);//delete defencer sodier from tree
            C[i]->attackerArmysIn.push(attackerArmysInBACKUP[j]);//push again attacker soldier in queue

        }
    }
    cout << C[CastleId]->deadStack.top() << endl;



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




