#include "StartGame.h"

StartGame::StartGame()
{
    cout << "Enter number of edges: ";
    cin >> E;

    setGraph();
    setCastles();
    choiceCastle();
    showTargetCastles();

    cout  << "\nEnter 1, for start the war: ";
    int f;
    cin >> f;
    if(f == 1) {
        startWars();
    }
    else{
        cout << "Wrong input! Good Luck...";
    }


    //ctor
}

StartGame::~StartGame()
{
    this->G = NULL;
    delete this->G;

    //dtor
}

void StartGame::setGraph(){
    G = new Graph(E);

    //Now we should get Edges from user
    //(i, j, distance)
    G->addEdge(0,1,5);
    G->addEdge(0,4,6);
    G->addEdge(1,2,3);
    G->addEdge(1,3,9);
    G->addEdge(1,4,1);
    G->addEdge(2,3,7);
    G->addEdge(3,4,2);
    G->printGraph();


    return;
}

void StartGame::setCastles(){
    //Now we should get Castle Details from user

    for(int i=0; i<E; i++){
        Castle* temp = new Castle(i, 100/E);
        C.push_back(temp);//max=220
        C[i]->setArmyTree();
    }



    for(int i=0; i<E; i++){
        int* listOfCastlesArmys = new int[E];
        //Bayad az aval set beshe chon pointere
        for(int i=0; i<E; i++){
            listOfCastlesArmys[i] = C[i]->getArmySize();
        }
        C[i]->distributingSoldiers(listOfCastlesArmys, G->getMatris(), E);
    }

}

void StartGame::choiceCastle(){
    cout << "All castle that exist: ";
    for(int i=0; i<E; i++){
        cout << i << ", ";
    }
    cout << "\nChoose one of them(Enter -1 to see their details): ";
    cin >> CastleId;

    if(CastleId != -1){
        cout << "Your castle is: " << CastleId << endl;
        return;
    }




    cout << "List of all castles that you can choice:\n\n";

    //list of all castles army size for showNeighbor()
    int* army = new int[E];
    for(int i=0; i<E; i++){
        army[i] = C[i]->getArmySize();
    }

    for(int i=0; i<E; i++){
        cout << "Castle id:\n" << C[i]->getId() << endl;
        cout << "Army size:\n" << C[i]->getArmySize() << endl;
        C[i]->showNeighbors(G->getMatris(), E, army);
        cout << endl;

    }
    cout << endl;

    cout << "Now choice your castle: ";
    cin >> CastleId;
    cout << "Your castle is: " << CastleId << endl;

}

void StartGame::showTargetCastles(){

    int* distributedArmys;
    distributedArmys = C[CastleId]->getDistributingSoldiersList();


    cout << "List of all castles that you can attack them:\n\n";
    for(int i=0; i<E; i++){
        if(G->getMatris()[CastleId][i] != 0){
            cout << "Castle id:                  " << i << endl;
            cout << "Army size:                  " << C[i]->getArmySize() << endl;
            cout << "Distance:                   " << G->getMatris()[CastleId][i] << " km" << endl;
            cout << "My distributed army size:   " << distributedArmys[i] << endl;
            cout << "Win chance(#):              " << (float)distributedArmys[i]/(float)C[i]->getArmySize() << endl;
            cout << "Soldiers status(#):         " << "Ready to attack" << endl;

            cout << endl;
        }


    }
}

void StartGame::startWars(){
    //send address of G, C
    War war(G, C, E, CastleId);

    return;
}
