#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr) {
	vector<int>res;

	sort(arr.begin(), arr.end());

	for(int i = 0; i < arr.size() / 2; i++) {
		res.push_back(arr[i]);
		res.push_back(arr[arr.size() - i - 1]);
	}

	if(arr.size() & 1) {
		res.push_back(arr[arr.size() / 2]);
	}

	int ans = 0;

	for(int i = 0; i < arr.size() - 1; i++) {
		ans += abs(res[i] - res[i + 1]);
	}

	ans += abs(res[arr.size() - 1] - arr[0]);

	return ans;
}

int main() {
	vector<int>arr = { 1, 2, 4, 8 };
	cout << solve(arr);

	// for(int x : res) cout << x << " ";
	return 0;	
}
