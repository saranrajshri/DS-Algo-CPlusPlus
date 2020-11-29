#include<bits/stdc++.h>
using namespace std;
#define V 5

void addEdge(vector<int> adjacencyList[], int u, int v) {
	adjacencyList[u].push_back(v);
	adjacencyList[v].push_back(u);	
}

void bfs(vector<int> adjacencyList[], int s) {
	vector<bool> visited(V, false);
	list<int> queue;

	visited[s] = true;
	queue.push_back(s);


	while(!queue.empty()) {
		s = queue.front();
		cout << s << " ";
		queue.pop_front();


		for(auto it = adjacencyList[s].begin(); it != adjacencyList[s].end(); it++) {
			if(!visited[*it]) {
				visited[*it] = true;
				queue.push_back(*it);
			}
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

    bfs(adjacencyList, 0);

	return 0;	
}
