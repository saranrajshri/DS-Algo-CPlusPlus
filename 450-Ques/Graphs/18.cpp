#include<bits/stdc++.h>
using namespace std;

vector<int> parent, rank;

struct Edge {
	int u, v, weight;
	bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

void makeSet(int v) {
	parent[v] = v;
	rank[v] = 0;
}

int find(int v) {
	if(parent[v] == v) return v;

	return find(parent[v]);
}

void Union(int u, int v) {
	int x = find(u);
	int y = find(v);

	if(x == y) return;
	if(rank[x] < rank[y]) {
		swap(rank[x], rank[y]);
	}
	parent[y] = a;

	if(rank[x] == rank[y]) {
		rank[x]++;
	}

}


void kruskalMST(vector<Edge>edgeList) {
	int cost = 0;
	vector<Edge>res;

	parent.resize(edgeList.size());
	rank.resize(edgeList.size());

	for(int i = 0; i < edgeList.size(); i++) {
		makeSet(i);
	}

	sort(edgeList.begin(), edgeList.end());

	for(Edge e: edgeList) {
		if(find(e.u) != find(e.v)) {
			cost += e.weight;
			res.push_back(e);
			Union(e.u, e.v);
		}
	}

	cout << cost << endl;
}

int main() {
	vector<Edge> edgeList;

	vector<vector<int>> arr = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};

	for(vector<int> x : arr) {
		Edge newEdge = Edge({x[0], x[1], x[2]});
		edgeList.push_back(newEdge);
	}

	kruskalMST(edgeList);

	return 0;	
}
