#include<bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	list<int> *adj;
public:
	Graph(int V);
	void addEdge(int u, int v);
	int solve();
	void dfs(int v, vector<bool>&visited);
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v) {
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::dfs(int v, vector<bool>&visited) {
	visited[v] = true;

	for(auto it = adj[v].begin(); it != adj[v].end(); it++) {
		if(visited[*it] == false) {
			dfs(*it, visited);
		}
	}
}

int Graph::solve() {
	vector<bool> visited(V, false);
	int components = 0;
	for(int i = 0; i < V; i++) {
		if(visited[i] == false) {
			dfs(i, visited);
			components++;
		}
	}

	return components - 1;
}


int main() {
	vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};
	
	Graph g(6);

	for(vector<int> arr : connections) {
		g.addEdge(arr[0], arr[1]);
	}

	cout << g.solve() << " ";
	
	return 0;	
}
