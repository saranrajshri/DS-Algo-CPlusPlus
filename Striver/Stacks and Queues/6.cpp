#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>arr) {
	vector<int>res(arr.size());
	stack<int>s;

	for(int i = arr.size() - 1; i >= 0; i--) {
		while(!s.empty() && s.top() >= arr[i]) s.pop();

		if(s.empty()) res[i] = INT_MAX;
		else res[i] = s.top();

		s.push(arr[i]);
	}

	return res;
}

int main() {
	vector<int>arr = {11, 13, 21, 3}; 
	vector<int> res = solve(arr);

	for(int x : res) cout << x << " ";
	return 0;	
}



