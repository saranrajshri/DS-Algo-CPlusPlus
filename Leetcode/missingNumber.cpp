#include<bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> nums) {
	int missing = 0;
	for(int x : nums) {
		missing ^= x;
	}

	for(int i = 0; i <= nums.size(); i++) {
		missing ^= i;
	}

	return missing;
}

int main() {
	vector<int> nums = {3, 0, 1};
	cout << missingNumber(nums);	
	return 0;
}