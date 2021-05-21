#include "bits/stdc++.h"
#define int long long
using namespace std;


unordered_map<int, vector<int>> adj;

bool dfsHelper(int u, vector<bool>&visited, vector<bool>&recStack) {
	visited[u] = true;
	recStack[u] = true;

	for(int v : adj[u]) {
		if(!visited[v] && dfsHelper(v, visited, recStack)) return true;
		else if(recStack[v]) return true;
	}

	recStack[u] = false;
	return false;
}

bool isCylic(int n) {
	vector<bool> visited(n + 1);
	vector<bool> recStack(n + 1);

	for(int i = 1; i < n + 1; i++) {
		if(!visited[i] && dfsHelper(i, visited, recStack)) return true;
	}

	return false;
}

void helper1(int u, vector<bool>&visited, vector<int> &dp) {
	visited[u] = true;

	for(int v : adj[u]) {
		if(!visited[v]) {
			helper1(v, visited, dp);
		}
		// cout << " ex" << endl;
		dp[u] = max(dp[u], 1 + dp[v]);
	}
}

int helper(int n) {
	vector<bool> visited(n + 1);
	vector<int> dp(n + 1);

	for(int i = 0; i < n + 1; i++) {
		if(!visited[i]) {
			helper1(i, visited, dp);
		}
	}

	int ans = 0;
	for(int i = 0; i < n + 1; i++) {
		ans = max(ans, dp[i]);
		// cout << dp[i] << " ";
	}

	return ans;
}

void solve(vector<vector<int>> arr, int n) {
	if(isCylic(n)) {
		cout << -1;
	}else{
		for(vector<int> edge : arr) {
			adj[edge[0]].push_back(edge[1]);
		}

		cout << helper(n);
	}
}

int32_t main() {
	vector<vector<int>> arr =  {{1, 2}, {1, 3}, {3, 2}, {2, 4}, {3, 4}};
	solve(arr, 5);
	return 0;	
}
