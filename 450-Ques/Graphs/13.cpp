#include<bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	list<int>*adj;
public:
	Graph(int V);
	void addEdge(int u, int w);
	vector<int> topologicalSort();
	bool isCyclic();
	bool isCyclicHelper(vector<bool>&visited, vector<bool>&recStack, int v);
	void topologicalSortHelper(vector<bool>&visited, stack<int>&s, int v);
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdge(int u, int w) {
	adj[u].push_back(w);
}

bool Graph::isCyclicHelper(vector<bool>&visited, vector<bool>&recStack, int v) {
	if(visited[v] == false) {
		recStack[v] = true;
		visited[v] = true;

		for(auto it = adj[v].begin(); it != adj[v].end(); it++) {
			if(visited[*it] == false && isCyclicHelper(visited, recStack, *it)) return true;
			else if(recStack[*it]) return true;
		}
	}

	recStack[v] = false;
	return false;
}

bool Graph::isCyclic() {
	vector<bool> visited(V, false);
	vector<bool> recStack(V, false);

	for(int i = 0; i < V; i++) {
		if(isCyclicHelper(visited, recStack, i)) return true;
	}

	return false;
}

void Graph::topologicalSortHelper(vector<bool>&visited, stack<int>&s, int v) {
	visited[v] = true;

	for(auto it = adj[v].begin(); it != adj[v].end(); it++) {
		if(visited[*it] == false) {
			topologicalSortHelper(visited, s, *it);
		}
	}

	s.push(v);
}

vector<int> Graph::topologicalSort() {
	vector<int>res;
	stack<int>s;
	vector<bool> visited(V, false);

	for(int i = 0; i < V; i++) {
		if(visited[i] == false) {
			topologicalSortHelper(visited, s, i);
		}
	}	


	while(!s.empty()) {
		res.push_back(s.top());
		s.pop();
	}

	return res;
}

int main() {

    Graph g(6); 
    g.addEdge(5, 2); 
    g.addEdge(5, 0); 
    g.addEdge(4, 0); 
    g.addEdge(4, 1); 
    g.addEdge(2, 3); 
    g.addEdge(3, 1); 
  
  	if(!g.isCyclic()) {
	    vector<int>res = g.topologicalSort();
    	for(int x : res) cout << x << " ";
	}

	return 0;	
}
