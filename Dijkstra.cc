#include <vector>
#include <set>

using namespace std;

struct neighbour {
    int dst;
    int weight;
    neighbour(int d, int w) : dst(d), weight(w) {}
};

typedef vector<vector<neighbour>> Graph;

void DijkstraComputePaths(Graph& graph, vertex_t src) {
    int n = graph.size();
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
            if(!final[i] && minDis[i] < min) {
                minVal = minDis[i];
                minIdx = i;
            }
        }
        final[minIdx] = true;
        
    }
}
