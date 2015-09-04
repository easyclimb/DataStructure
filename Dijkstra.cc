/*****************用邻接矩阵 Adjacency Matrix表示图*********************************/
#include <iostream>

using namespace std;

#define n 9

void Dijkstra(int graph[n][n], int src) {
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
            if(!final[j] && graph[minIdx][j] && minDis[minIdx] + graph[minIdx][j] < minDis[j]) {
                minDis[j] = minDis[minIdx] + graph[minIdx][j];
                previous[j] = minIdx;
            }
        }
    }
    for(int i = 0; i < n; i++)
        cout << "To " << i << " " << minDis[i] << endl;
    for(int i = 0; i < n; i++) {
        stack<int> stk;
        int j = i;
        stk.push(j);
        while(j != src) {
            stk.push(previous[j]);
            j = previous[j];
        }
        while(!stk.empty()) {
            cout << stk.top() << ' ';
            stk.pop();
        }
        cout << endl;
    }
}

/************************用邻接表 Adjacency List表示图**********************/

struct neighbor {
    int dst;
    int weight;
    neighbor(int d, int w) : dst(d), weight(w) {}
};

typedef vector<vector<neighbor>> Graph;

void Dijkstra2(Graph graph, int src) {
    int n = graph.size();
    int minDis[n], previous[n];
    bool final[n];
    for(int i = 0; i < n; i++) {
        minDis[i] = INT_MAX;
        previous[i] = -1;
        final[i] = false;
    }
    minDis[src] = 0;
    for(int i = 0; i < n; i++) {
        int minVal = INT_MAX, minIdx = -1;
        for(int j = 0; j < n; j++) {
            if(!final[j] && minDis[j] < minVal) {
                minVal = minDis[j];
                minIdx = j;
            }
        }
        final[minIdx] = true;
        vector<neighbor> neighbors = graph[minIdx];
        for(auto nei : neighbors) {
            if(!final(nei.dst) && minVal + nei.weight < minDis[nei.dst]) {
                minDis[nei.dst] = minVal + nei.weight;
                previous[nei.dst] = minIdx;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << "Path:" << endl;
        stack<int> stk;
        stk.push(i);
        int j = i;
        while(j != src) {
            stk.push(previous[j]);
            j = previous[j];
        }
        while(!stk.empty()) {
            cout << stk.top() << ' ';
            stk.pop();
        }
        cout << "Dis: " << minDis[i] << endl;
    }
}
