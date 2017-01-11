#ifndef CALCULATE_H_INCLUDED
#define CALCULATE_H_INCLUDED
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stack>
#define INFINITY 9999

using namespace std;

struct info
{
    string ip;
    int num;
};

class router
{
private:
    int table[20][20];
    int size;//the number of roots(it changes with the using of function delet and add)
    info router_info[20];//the information of routers
public:
    router();
    void deleteVertex(router &G);
    void deleteEdge(router &G);
    void addVertex(router &G);
    void addEdge(router &G);
    void calculate(router &G);
    void createVertices(router &G);
    void createEdges(router &G);
    void createGraph(router &G);
    void save();
    int getVertexPos(int v)
    {
        for(int i=0; i<size; i++)
            if(router_info[i].num==v)return i;
        return -1;
    }
};

#endif // CALCULATE_H_INCLUDED
