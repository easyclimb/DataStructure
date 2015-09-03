/*****************用邻接矩阵 Adjacency Matrix表示图*********************************/
#include <iostream>

using namespace std;

#define n 9

void Dijkstra(int graph[n][n], vertex_t src) {
    int minDis[n], previous[n];
    bool final[n];
    for(int i = 0; i < n; i++) {   //initialization
        minDis[i] = INT_MAX;
        previous[i] = -1;
        final[i] = false;
    }
    minDis[src] = 0;
    for(int i = 0; i < n-1; i++) {
        int minVal = INT_MAX, minIdx = -1;
        for(int i = 0; i < n; i++) {
            if(!final[i] && minDis[i] < minVal) {
                minVal = minDis[i];
                minIdx = i;
            }
        }
        final[minIdx] = true;
        for(int j = 0; j < n; j++) {
            if(!final[j] && graph[minIdx][j] && minDis[minIdx] + graph[minIdx][j] < minDis[j])
                minDis[j] = minDis[minIdx] + graph[minIdx][j];
        }
    }
    for(int i = 0; i < n; i++)
        cout << "To " << i << " " << minDis[i] << endl;
}

/************************用邻接表 Adjacency List表示图**********************/

struct neighbour {
    int dst;
    int weight;
    neighbour(int d, int w) : dst(d), weight(w) {}
};

typedef vector<vector<neighbour>> Graph;

void Dijkstra2(Graph graph, int src) {
    int n = graph.size();
    bool final[n];
    int minDis[n], previous[n];
    for(int i = 0; i < n; i++) {
        final[i] = false;
        minDis[i] = INT_MAX;
        previous[i] = -1;
    }
    minDis[src] = 0;
    set<pair<int,int>> que;
    que.insert({minDis[src], src});
    while(!que.empty()) {
        
    }
}
