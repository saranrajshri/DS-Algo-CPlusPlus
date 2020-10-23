#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Sort + Two Pointers
	Time - O(N log N);
	Space - O(1);
*/ 

pair<int, int> findPairWithDiff(vector<int> nums, int diff) {
	sort(nums.begin(), nums.end());

	pair<int, int>res;
	int left = 0;
	int right = nums.size() - 1;

	while(left < right) {
		int currentDiff = nums[right] - nums[left];
		if(currentDiff == diff) {
			res.first = nums[left];
			res.second = nums[right];

			return res;
		} 
		else if(currentDiff < diff) left++;
		else right--;
	}

	return make_pair(-1, -1);
}

int main() {
	vector<int> nums = {5, 20, 3, 2, 5, 80};
	int diff = 78;
	pair<int, int> res = findPairWithDiff(nums, diff);
	
	cout << res.first << " " << res.second;
	return 0;
}