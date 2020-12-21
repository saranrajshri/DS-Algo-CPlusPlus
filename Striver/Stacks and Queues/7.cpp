#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>arr, int k) {
	deque<int>q;
	vector<int>res;

	for(int i = 0; i < arr.size(); i++) {
		while(!q.empty() && arr[q.back()] <= arr[i]) q.pop_back();

		q.push_back(i);

		while(i - k == q.front()) q.pop_front();

		if(i >= k - 1) res.push_back(arr[q.front()]);
	}

	return res;
}

int main() {
	vector<int>arr = {1,3,-1,-3,5,3,6,7};
	vector<int>res = solve(arr, 3);

	for(int x : res) cout << x << " ";	
	return 0;	
}
