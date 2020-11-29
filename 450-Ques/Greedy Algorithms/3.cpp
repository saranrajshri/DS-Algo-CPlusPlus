#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr, int k) {
	int minNum = *min_element(arr.begin(), arr.end());
	int count = 0;

	for(int i = 0; i < arr.size(); i++) {
		int diff = arr[i] - minNum;
		if(diff > k) count++;
	}

	return count;
}

int main() {
	vector<int> arr = {1, 5, 1, 2, 5, 1};
	int k = 3;

	cout << solve(arr, k);
	return 0;	
}
