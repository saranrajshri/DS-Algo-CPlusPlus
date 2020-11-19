#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>arr, int k) { 
	deque<int>q;
	vector<int> res;

	for(int i = 0; i < k; i++) {
		if(arr[i] < 0) q.push_back(i);
	}

	for(int i = k; i < arr.size(); i++) {
		if(!q.empty()) {
			res.push_back(arr[q.front()]);
		}else{
			res.push_back(0);
		}

		while(!q.empty() && q.front() == i - k) {
			q.pop_front();
		}


		if(arr[i] < 0) {
			q.push_back(i);
		}
	}

	if(!q.empty()) {
		res.push_back(arr[q.front()]);
	}else{
		res.push_back(0);
	}
	
	return res;
} 

int main() {
	vector<int> arr = {12, -1, -7, 8, -15, 30, 16, 28};
	int k = 3;

	vector<int> res = solve(arr, k);
	for(int x : res) cout << x << " ";
	return 0;	
}

