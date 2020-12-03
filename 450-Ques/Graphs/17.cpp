#include<bits/stdc++.h>
using namespace std;

class Graph {
	int V;
	list<int>*adj;
public:
	Graph(int V);
	void addEdges(int u, int v);
	void topologicalSortHelper(vector<bool>&visited, stack<int>&s, int v);
	vector<char> topologicalSort();
};

Graph::Graph(int V) {
	this->V = V;
	adj = new list<int>[V];
}

void Graph::addEdges(int u, int v) {
	adj[u].push_back(v);
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

vector<char> Graph::topologicalSort() {
	vector<bool> visited(V, false);
	stack<int> s;
	vector<char> res;


	for(int i = 0; i < V; i++) {
		if(visited[i] == false) {
			topologicalSortHelper(visited, s, i);
		}
	}

	while(!s.empty()) {
		res.push_back(s.top() + 'a');
		s.pop();
	}

	return res;
}

vector<char> solve(vector<string> words) {
	Graph g(words.size());

	for(int i = 0; i < words.size() - 1; i++) {
		string word1 =  words[i];
		string word2 = words[i + 1];

		int j = 0;
		while(j < word1.size() && j < word2.size()) {
			if(word1[j] != word2[j]) break;
			else j++;
		}

		g.addEdges(word1[j] - 'a', word2[j] - 'a');
	}

	vector<char> res = g.topologicalSort();

	return res;
}

int main() {
	vector<string> words = {"caa", "aaa", "aab"}; 
	vector<char> res = solve(words);

	for(char x : res)cout << x << " ";
	return 0;	
}
