#include<bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	list<int>*adj;
public:
	Graph(int V);
	void addEdge(int u, int v);
	bool isCyclic();
	bool isCyclicHelper(vector<bool>&visited, vector<bool>&recStack, int v);
	bool topologicalSort();
	void topologicalSortHelper(vector<bool>&visited, int v);
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int v) {
	adj[u].push_back(v);
}

bool Graph::isCyclicHelper(vector<bool>&visited, vector<bool>&recStack, int v) {
	if(visited[v] == false) {
		visited[v] = true;
		recStack[v] = true;

		for(auto it = adj[v].begin(); it != adj[v].end(); it++) {
			if(visited[*it] == false && isCyclicHelper(visited, recStack, *it)) return true;
			else if(recStack[*it]) return true;
 		}
	}

	recStack[v] = false;
	return false;
}

bool Graph::isCyclic() {
	vector<bool>visited(V, false);
	vector<bool>recStack(V, false);

	for(int i = 0; i < V; i++) {
		if(isCyclicHelper(visited, recStack, i)) return true;
	}

	return false;
}

void Graph::topologicalSortHelper(vector<bool>&visited, int v) {
	visited[v] = true;

	for(auto it = adj[v].begin(); it != adj[v].end(); it++) {
		if(visited[*it] == false) {
			topologicalSortHelper(visited, *it);
		}
	}
}

bool Graph::topologicalSort() {
	vector<bool>visited(V, false);

	for(int i = 0; i < V; i++) {
		if(visited[i] == false) {
			topologicalSortHelper(visited, i);
		}else{
			return false;
		}
	}

	return true;
}

int main() {
	Graph g1(2);
	g1.addEdge(1, 0);

	if(!g1.isCyclic()) {
		if(g1.topologicalSort()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	Graph g2(2);
	g2.addEdge(1, 0);
	g2.addEdge(0, 1);

	if(!g2.isCyclic()) {
		if(g2.topologicalSort()) cout << "Yes" << endl;
		else cout << "No" << endl;
	}

	return 0;	
}
