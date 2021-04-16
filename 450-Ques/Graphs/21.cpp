#include<bits/stdc++.h>
using namespace std;
#define V 7
#define pb push_back

unordered_map<int,vector<int>> adj;

void dfs(int u, vector<int> &disc, vector<int> &low, vector<bool>&inStack, stack<int>&s) {
   static int time = 0;

   disc[u] = time;
   low[u] = time;
   time++;
   inStack[u] = true;
   s.push(u);

   for(int v : adj[u]) {
   		if(disc[v] == -1) {
   			dfs(v, disc, low, inStack, s);
   			low[u] = min(low[u], low[v]);
   		}else if(inStack[v]) {
   			low[u] = min(low[u], disc[v]);
   		}
   }

   if(low[u] == disc[u]) {
   		cout << "SCC is : ";
   		while(s.top() != u) {
   			cout << s.top() << " ";
   			inStack[s.top()] = false; 
   			s.pop();
   		} 
   		cout << s.top() << endl;
   		inStack[s.top()] = false;
   		s.pop();
   }
} 

void solve() {
	vector<int> disc(V, -1);
	vector<int> low(V, -1);
	vector<bool> inStack(V, false);
	stack<int> s;

	for(int i = 0; i < V; i++) {
		if(disc[i] == -1) {
			dfs(i, disc, low, inStack, s);
		}
	}
}

int main() {

	adj[0].pb(1);
	adj[1].pb(2);
	adj[1].pb(3);
	adj[3].pb(4);
	adj[4].pb(0);
	adj[4].pb(5);
	adj[4].pb(6);
	adj[5].pb(6);
	adj[6].pb(5);

	solve();


	return 0;
}