#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> solve(vector<int>arr, int k) {
	deque<int>maxQ;
	deque<int>minQ;
	vector<pair<int, int>> res;

	for(int i = 0; i < arr.size(); i++) {
		while(!maxQ.empty() && arr[maxQ.back()] <= arr[i]) maxQ.pop_back();
		while(!minQ.empty() && arr[minQ.back()] >= arr[i]) minQ.pop_back();

		maxQ.push_back(i);
		minQ.push_back(i);

		while(!maxQ.empty() && maxQ.front() <= i - k) maxQ.pop_front();
		while(!minQ.empty() && minQ.front() <= i - k) minQ.pop_front();

		if(i >= k - 1) {
			res.push_back(make_pair(arr[minQ.front()], arr[maxQ.front()]));
		}

	}
	return res;
}

int main() {
	vector<int>arr = {1,3,-1,-3,5,3,6,7};
	int k = 3;

	vector<pair<int, int>> res = solve(arr, k);

	for(pair<int, int> x : res) {
		cout << x.first << " " << x.second << endl;
	}
	return 0;	
}
