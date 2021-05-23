#include "bits/stdc++.h"
#define int long long
using namespace std;

vector<vector<int>> dp(300030, vector<int>(28));
vector<int> deg(300030);
vector<int> adj[300030];

int32_t main() {
	int n, m;
	cin >> n >> m;

	string str;
	cin >> str;

	str = '*' + str;

	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adj[x].push_back(y);
		deg[y]++;
	}

	queue<int> q;
	int count = n;
	int pos = 0;

	for(int i = 1; i < n + 1; i++) {
		if(deg[i] == 0) q.push(i);
		dp[i][str[i] - 'a']++;
	}

	while(!q.empty()) {
		int x = q.front();
		q.pop();
		--count;

		for(auto &i : adj[x]) {
			for(int j = 0; j < 26; j++) {
				dp[i][j] = max(dp[i][j], dp[x][j] + (j == (str[i] - 'a')));
				pos = max(pos, dp[i][j]);
			}
			--deg[i];
			if(deg[i] == 0) {
				q.push(i);
			}
		}
	}

	if(count > 0) {
		cout << -1 << endl;
	}
	else {
		cout << pos << endl;
	}
	
	return 0;	
}
