#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
	unordered_map<int, int> parent;
public:
	DisjointSet(vector<int> wholeSet);
	int find(int x);
	void Union(int m, int n);
};

DisjointSet::DisjointSet(vector<int>wholeSet) {
	for(int x : wholeSet) {
		parent[x] = x;
	}
}

int DisjointSet::find(int x) {
	if(parent[x] == x) return x;
	
	return find(parent[x]);
}

void DisjointSet::Union(int m, int n) {
	int x = find(m);
	int y = find(n);

	if(x == y) return;

	parent[x] = y;
}

int main() {
	vector<int>arr = { 6,7,1,2,3 };
	DisjointSet dis(arr);
	dis.Union(7, 6);
	dis.Union(2, 3);
	dis.Union(7, 2);


	if(dis.find(7) == dis.find(6)) 
      cout << "Yes" << endl;
    else
      cout<<"No";
    if (dis.find(2) == dis.find(7))
      cout << "Yes" << endl;
    else
      cout << "No";
    
    return 0;
}
