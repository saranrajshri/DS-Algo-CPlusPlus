#include<bits/stdc++.h>
using namespace std;
#define V 5

void addEdge(vector<int> adjacenyList[], int u, int w) {
	adjacenyList[u].push_back(w);
}

bool isCycliHelper(vector<int> adjacenyList[], int v, vector<bool> &visited, vector<bool> &recStack) {
	if(visited[v] == false) {
		visited[v] = true;
		recStack[v] = true;

		for(auto it = adjacenyList[v].begin(); it != adjacenyList[v].end(); it++) {
			if(visited[*it] == false && isCycliHelper(adjacenyList, *it, visited, recStack)) {
				return true;
			}else if(recStack[*it]) {
				return true;
			}
		}
 	}

	recStack[v] = false;
	return false;
}

bool isCyclic(vector<int> adjacenyList[]) {
	vector<bool> visited(V, false);
	vector<bool> recStack(V, false);

	for(int i = 0; i < V; i++) {
		if(isCycliHelper(adjacenyList, i, visited, recStack)) {
			return true;
		}
	}

	return false;
}

int main() {
	vector<int> adjacenyList[V];

 	addEdge(adjacenyList, 0, 1); 
    addEdge(adjacenyList, 0, 2); 
   	addEdge(adjacenyList, 1, 2); 
    addEdge(adjacenyList, 2, 0); 
    addEdge(adjacenyList, 2, 3); 
    addEdge(adjacenyList, 3, 3); 

    if(isCyclic(adjacenyList)) {
    	cout << "Yes" << endl;
    }else{
    	cout << "No" << endl;
    }

	return 0;	
}
