//DFS for graph
//Time Complexity : O(V + E), V :  Number of Vertices, E : Number of Edges
//Space Complexity : O(V) --> visited boolean array

//topological Sort
//Time Complexity ：O(V + E)
//Space Complexity : O(V) --> visited, stack

#include <iostream>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

//a directed graph using adjacent lists representation
class Graph {
public:
	Graph(int V);   //constructor
	void addEdge(int v, int w);   //add an adge to graph
	void DFS(int v);    //DFS traversal for the vertices reachable from v
	void DFS();     //print DFS traversal for the complete graph
	vector<int> topologicalSort();
	vector<int> topologicalSort2();
private:
	int V;   //No. of vertices
	vector<int> *adj;   //a vector containing adjacent lists
	void DFSRe(int v, bool visited[]);   //function usded by DFS
	void topologicalSortRe(int v, bool visited[], stack<int>& stk);
};

Graph::Graph(int V) {
	this->V = V;
	adj = new vector<int>[V];
}

void Graph::addEdge(int v, int w) {
	adj[v].push_back(w);
}

void Graph::DFSRe(int v, bool visited[]) {
	visited[v] = true;
	cout << v << " ";
	for (auto e : adj[v])
		if (!visited[e])
			DFSRe(e, visited);
}

void Graph::DFS(int v) {
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	DFSRe(v, visited);
}

void Graph::DFS() {
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	for (int i = 0; i < V; i++)
		if (!visited[i])
			DFSRe(i, visited);
}

void Graph::topologicalSortRe(int v, bool visited[], stack<int>& stk) {
	visited[v] = true;
	for (auto e : adj[v])
		if (!visited[e])
			topologicalSortRe(e, visited, stk);
	stk.push(v);
}

//DFS
vector<int> Graph::topologicalSort() {
	bool *visited = new bool[V];
	for (int i = 0; i < V; i++)
		visited[i] = false;
	stack<int> stk;
	vector<int> ret;
	for (int i = 0; i < V; i++) {
		if (!visited[i])
			topologicalSortRe(i, visited, stk);
	}
	while (!stk.empty()) {
		ret.push_back(stk.top());
		stk.pop();
	}
	return ret;
};

//BFS
vector<int> Graph::topologicalSort2() {
	vector<int> indegree(V);
	for (int i = 0; i < V; i++)
		for (auto v : adj[i])
			indegree[v]++;
	queue<int> que;
	for (int i = 0; i < V; i++)
		if (indegree[i] == 0)
			que.push(i);
	vector<int> ret;
	int count = 0;
	while (!que.empty()) {
		int i = que.front();
		que.pop();
		ret.push_back(i);
		count++;
		for (auto e : adj[i]) {
			indegree[e]--;
			if (indegree[e] == 0)
				que.push(e);
		}
	}
	if (count == V) return ret;
	return{};
}

void show(vector<int>& vec) {
	for (auto v : vec)
		cout << v << " ";
	cout << endl;
}

int main()
{
	Graph g(6);
	g.addEdge(4, 0);
	g.addEdge(4, 1);
	g.addEdge(5, 0);
	g.addEdge(5, 2);
	g.addEdge(2, 3);
	g.addEdge(3, 1);
	vector<int> ret;
	ret = g.topologicalSort();
	show(ret);
	ret = g.topologicalSort2();
	show(ret);
	getchar();
	return 0;
}
