#include "Graph.h"

Graph::Graph(int v)
{
    this->V = v;
    matris = new int*[v];
    for(int i = 0; i < v; ++i)
        matris[i] = new int[v];
    //ctor
}

Graph::~Graph()
{
    //dtor
}


void Graph::addEdge(int u, int v, int dis)
{
    matris[u][v] = dis;
    matris[v][u] = dis;

    return;
}

void Graph::printGraph()
{
    for (int i = 0; i < V; ++i){
        for(int j=0; j<V; ++j){
            cout << matris[i][j] << " ";
        }
        cout << endl;
    }
    return;
}

int** Graph::getMatris(){
    return this->matris;
}
