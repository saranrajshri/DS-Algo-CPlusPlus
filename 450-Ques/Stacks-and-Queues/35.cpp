#include<bits/stdc++.h>
using namespace std;

vector<string> solve(string str) {
	queue<char>q;
	unordered_map<char, int>m;
	vector<string> res;

	for(int i = 0; i < str.size(); i++) {
		q.push(str[i]);

		m[str[i] - 'a']++;

		while(!q.empty()) {
			if(m[q.front() - 'a'] > 1) q.pop();
			else{
				res.push_back(to_string(q.front()));
				break;
			}
		}

		if(q.empty()) res.push_back("-1");
	}

	return res;
}

int main() {
	string str = "aabc";
	vector<string> res = solve(str);
	for(string x : res) {
		cout << x << " ";
	}
	return 0;	
}

