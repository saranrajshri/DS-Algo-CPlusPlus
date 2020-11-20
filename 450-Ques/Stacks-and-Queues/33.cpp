#include<bits/stdc++.h>
using namespace std;

int solve(string str, int k) {
	unordered_map<char, int>m;
	priority_queue<int>q;

	for(char x : str) m[x]++;

	for(auto it : m) {
		q.push(it.second);
	}

	while(k--) {
		int temp = q.top();
		q.pop();

		temp--;
		q.push(temp);
	}

	int res = 0;
	while(!q.empty()) {
		int temp = q.top();
		q.pop();

		res += temp * temp;
	}


	return res;
}


int main() {
	string str = "abbccc";
	int k = 2;
	cout << solve(str, k);
	return 0;	
}
