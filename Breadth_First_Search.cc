#include <iostream>
#include <list>

using namespace std;

class Graph {
public:
    Graph(int V);
    void addEdge(int u, int v);
    void BFS
private:
    int V;
    vector<list<int>> adj;
};
