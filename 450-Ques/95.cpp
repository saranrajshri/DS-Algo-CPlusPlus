#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Jump Search
	Time - O(N);
	Space - O(1);
*/		

int jumpSearchByK(vector<int> nums, int target, int k) {
	int i = 0;

	while(i < nums.size()) {
		if(nums[i] == target) return i;

		// Increment the index
		i = i + max(1, abs(nums[i] - target) / k);
	}

	return -1;
}

int main() {
	vector<int> nums = {2, 4, 5, 7, 7, 6};
	int target = 6;
	int k = 2;
	
	cout << jumpSearchByK(nums, target, k);
	return 0;
}