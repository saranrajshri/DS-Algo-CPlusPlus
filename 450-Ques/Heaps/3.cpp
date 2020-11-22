#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>arr, int k) {
	deque<int>q;
	vector<int>res;

	for(int i = 0; i < arr.size(); i++) {
		while(!q.empty() && arr[q.back()] <= arr[i]) q.pop_back();

		q.push_back(i);

		while(!q.empty() && q.front() <= i - k) q.pop_front();

		if(i >= k - 1) res.push_back(arr[q.front()]);
 	}
 	return res;
}

int main() {
	vector<int>arr = {1, 2, 3, 1, 4, 5, 2, 3, 6};
	int k = 3;
	vector<int>res = solve(arr, 3);

	for(int x : res) cout << x << " ";
	return 0;	
}
