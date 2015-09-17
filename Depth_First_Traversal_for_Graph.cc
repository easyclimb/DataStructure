#include <iostream>
#include <vector>

using namespace std;

//a directed graph using adjacent lists representation
class Graph {
public:
    Graph(int V);   //constructor
    void addEdge(int v, int w);   //add an adge to graph
    void DFS(int v);    //DFS traversal for the vertices reachable from v
private:
    int V;   //No. of vertices
    vector<int> *adj;   //a vector containing adjacent lists
    void DFSRe(int v, bool visited[]);   //function usded by DFS
};

Graph::Graph(int v) {
    this->V = V;
    adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w) {
    adj[v].push_back(w);
}

void Graph::DFSRe(int v, bool visited[]) {
    visited[v] = true;
    cout << v << " ";
    for(auto e : adj[v])
        if(!visited[e])
            DFSRe(e, visited);
}

void Graph::DFS(int v) {
    bool *visited = new bool[V];
    for(int i = 0; i < V; i++)
        visited[i] = false;
    DFSRe(v, visited);
}

int main() 
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.DFS(0);
    return 0;
}
