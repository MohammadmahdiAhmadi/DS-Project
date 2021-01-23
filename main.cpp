#include <iostream>
using namespace std;

#include "Graph.h"

int main()
{
    //Number of Edge
    int e;
    cin >> e;
    Graph g(e);

    //(i, j, distance)
    g.addEdge(0,1,5);
    g.addEdge(0,4,6);
    g.addEdge(1,2,3);
    g.addEdge(1,3,9);
    g.addEdge(1,4,15);
    g.addEdge(2,3,10);
    g.addEdge(3,4,2);
    g.printGraph();


    return 0;
}
