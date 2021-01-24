#include <iostream>
using namespace std;

#include "Graph.h"
#include "Castle.h"
#include "Avl.h"

#define OC 24 //OutputCapacity
#define SA 2  //SpeedOfArmy
int main()
{
    //Number of Edge
    int e;
    cin >> e;
    Graph g(e);

    //Now we should get Edges from user
    //(i, j, distance)
    g.addEdge(0,1,5);
    g.addEdge(0,4,6);
    g.addEdge(1,2,3);
    g.addEdge(1,3,9);
    g.addEdge(1,4,1);
    g.addEdge(2,3,7);
    g.addEdge(3,4,2);
    g.printGraph();

    //Now we should get Castle Details from user
    vector<Castle> C;
    for(int i=0; i<e; i++){
        C.push_back(Castle(i, 100/e));//max=220
        C[i].setArmyTree();
    }
    C[0].showNeighbors(g.getMatris(), e);


    return 0;
}
