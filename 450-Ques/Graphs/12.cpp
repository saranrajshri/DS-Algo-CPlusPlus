#include<bits/stdc++.h>
using namespace std;

/*
	time - O(VlogE)
	Space - O(V);
*/

class Graph {
	int V;
	list<pair<int, int>> *adj;
public:
	Graph(int V);
	void addEdge(int u, int v, int w);
	void solve(int source);
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<pair<int, int>>[V];
}

void Graph::addEdge(int u, int v, int w) {
	adj[u].push_back(make_pair(w, v));
	adj[v].push_back(make_pair(w, u));
}

void Graph::solve(int source) {
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
	vector<int> distance(V, INT_MAX);

	distance[source] = 0;
	minHeap.push(make_pair(0, source));

	while(!minHeap.empty()) {
		pair<int, int> currentNode = minHeap.top();
		minHeap.pop();

		int currentNodeVertex = currentNode.second;

		for(auto it = adj[currentNodeVertex].begin(); it != adj[currentNodeVertex].end(); it++) {
			int adjNodeVertex = (*it).second;
			int adjNodeWeight = (*it).first;

			if(distance[currentNodeVertex] + adjNodeWeight < distance[adjNodeVertex]) {
				distance[adjNodeVertex] = distance[currentNodeVertex] + adjNodeWeight;
				minHeap.push(make_pair(distance[adjNodeVertex], adjNodeVertex));
			}
		} 
	}

	for(int i = 0; i < V; i++) {
		cout << i << " " << distance[i] << endl;
	}
}

int main() {
	int V = 9; 
	Graph g(V); 
  
    g.addEdge(0, 1, 4); 
    g.addEdge(0, 7, 8); 
    g.addEdge(1, 2, 8); 
    g.addEdge(1, 7, 11); 
    g.addEdge(2, 3, 7); 
    g.addEdge(2, 8, 2); 
    g.addEdge(2, 5, 4); 
    g.addEdge(3, 4, 9); 
    g.addEdge(3, 5, 14); 
    g.addEdge(4, 5, 10); 
    g.addEdge(5, 6, 2); 
    g.addEdge(6, 7, 1); 
    g.addEdge(6, 8, 6); 
    g.addEdge(7, 8, 7); 
  
    g.solve(0); 
}
