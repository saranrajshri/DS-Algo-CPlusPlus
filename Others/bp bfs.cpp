#include "bits/stdc++.h"
#define int long long
using namespace std;

int32_t main() {
	int n, m;
	cin >> n >> m;

	vector<vector<int>> dp(400040, vector<int>(28));
	vector<int> indegree(400040);
	vector<int> adjList[400040];

	string str;
	cin >> str;

	str = '*' + str;

	for(int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adjList[x].push_back(y);
		indegree[y]++;
	}

	queue<int> que;
	int haveCount = n;
	int finalRes = 0;

	for(int i = 1; i < n + 1; i++) {
		if(indegree[i] == 0) {
			que.push(i);
		}

		char currentChar = str[i];
		dp[i][currentChar - 'a']++;
	}

	while(que.size() > 0) {
		int frontElement = que.front();
		--haveCount;
		que.pop();

		for(auto &i : adjList[frontElement]) {			
			for(int j = 0; j < 26; j++) {
				char currentChar = str[i];
				bool expr = (j == (currentChar - 'a'));
				dp[i][j] = max(dp[i][j], dp[frontElement][j] + expr);
				finalRes = max(finalRes, dp[i][j]);
			}

			--indegree[i];
			
			if(indegree[i] == 0) {
				que.push(i);
			}
		}
	}

	if(haveCount > 0) {
		cout << -1 << endl;
	}
	else {
		cout << finalRes << endl;
	}
	
	return 0;	
}

/*

1:

5 4
abaca
1 2
1 3
3 4
4 5

3

2:
6 6
xzyabc
1 2
3 1
2 3
5 4
4 3
6 4

-1

3:
10 14
xzyzyzyzqx
1 2
2 4
3 5
4 5
2 6
6 8
6 5
2 10
3 9
10 9
4 6
1 10
2 8
3 7

4	


4:
1 1
f
1 1

-1

*/