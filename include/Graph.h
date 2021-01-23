#ifndef GRAPH_H
#define GRAPH_H

#include<bits/stdc++.h>
using namespace std;

#include "Castle.h"

class Graph
{
    friend class Castle;
    public:
        Graph(int v);
        virtual ~Graph();

        void addEdge(int u, int v, int dis);
        void printGraph();
        int** getMatris();

    protected:

    private:
        int V;
        int** matris;
};

#endif // GRAPH_H
