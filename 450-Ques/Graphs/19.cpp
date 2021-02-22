#include<bits/stdc++.h>
using namespace std;
#define V 5


int getMinKey(vector<int> values, vector<bool> visited) {
	int minValue = INT_MAX;
	int minIndex = -1;

	for(int i = 0; i < V; i++) {
		if(visited[i] == false && values[i] < minValue) {
			minValue = values[i];
			minIndex = i;
		}
	}

	return minIndex;
}

void printMST(vector<int> parent, vector<vector<int>> graph) {
	for(int i = 1; i < V; i++) {
		cout << parent[i] << " - " << i << " " << graph[i][parent[i]] << endl;
	}
}

void solve(vector<vector<int>> graph) {
	vector<bool> visited(V, false);	
	vector<int> parent(V, 0);
	vector<int> values(V, INT_MAX);

	values[0] = 0;
	parent[0] = -1;

	for(int i = 0; i < V - 1; i++) {
		int u = getMinKey(values, visited);
		visited[u] = true;

		for(int v = 0; v < V; v++) {
			if(graph[u][v] && visited[v] == false && graph[u][v] < values[v]) {
				parent[v] = u;
				values[v] = graph[u][v];
			}
		}
	}

	printMST(parent, graph);
}

int main() {
	vector<vector<int>> graph = { { 0, 2, 0, 6, 0 },  
		                        { 2, 0, 3, 8, 5 },  
		                        { 0, 3, 0, 0, 7 },  
		                        { 6, 8, 0, 0, 9 },  
		                        { 0, 5, 7, 9, 0 } }; 
	solve(graph);                        
	return 0;	
}
