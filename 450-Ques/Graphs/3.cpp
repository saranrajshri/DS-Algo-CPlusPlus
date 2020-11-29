#include<bits/stdc++.h>
using namespace std;
#define V 5

void addEdge(vector<int> adjacencyList[], int u, int v) {
	adjacencyList[u].push_back(v);
	adjacencyList[v].push_back(u);
}

void dfsHelper(vector<int> adjacencyList[], int u, vector<bool>&visited) {
	visited[u] = true;
	cout << u << " ";

	for(int i = 0; i < adjacencyList[u].size(); i++) {
		if(visited[adjacencyList[u][i]] == false) {
			dfsHelper(adjacencyList, adjacencyList[u][i], visited);
		}
	}
}

void dfs(vector<int> adjacencyList[]) {
	vector<bool> visited(V, false);

	for(int i = 0; i < V; i++) {
		if(visited[i] == false){
			dfsHelper(adjacencyList, i, visited);
		}
	}
}

int main() {
	vector<int> adjacencyList[V];

	addEdge(adjacencyList, 0, 1); 
    addEdge(adjacencyList, 0, 4); 
    addEdge(adjacencyList, 1, 2); 
    addEdge(adjacencyList, 1, 3); 
    addEdge(adjacencyList, 1, 4); 
    addEdge(adjacencyList, 2, 3); 
    addEdge(adjacencyList, 3, 4); 

    dfs(adjacencyList);

	return 0;	
}
