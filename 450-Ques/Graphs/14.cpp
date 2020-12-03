#include<bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	list<int>*adj;
public:
	Graph(int V);
	void addEdge(int u, int v);
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
	vector<int> inDegree(V);
	vector<int> job(V);
}

void Graph::addEdge(int u, int v) {
	adj[u].push_back(v);

	inDegree[v]++;
}

vector<int> solve(int m, int n) {
	queue<int> q;

	for(int i = 1; i <= n; i++) {
		if(inDegree[i] == 0) {
			q.push(i);
			job[i] = 1;
		}
	}

	while(!q.empty()) {
		int currentJob = q.front();
		q.pop();

		for(auto it = adj[currentJob].begin(); it != adj[currentJob].end(); it++) {
			int adjJob = (*it);
			inDegree[adjJob]--;

			if(job[adjJob] <  1 + job[currentJob]) {
				job[adjJob] = max(job[adjJob], job[currentJob] + 1);
			}
			
			if(inDegree[adjJob] == 0) {
				q.push(adjJob);
			}
		}
	}
}


int main() {
	return 0;	
}
