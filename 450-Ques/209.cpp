#include<bits/stdc++.h>
using namespace std;

bool helper(vector<int>nums, int index, int sum, vector<unordered_map<int, bool>> &m) { 
	if(sum == 0) return true;

	if(sum < 0 || index >= nums.size()) return false;

	auto it = m[index].find(sum);
	if(it != m[index].end()) return it->second;

	return m[index][sum] = helper(nums, index + 1, sum, m) || helper(nums, index + 1, sum - nums[index], m);
}


bool canPartition(vector<int> nums) {
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if(sum % 2 != 0) return false;
	sum = sum / 2;

	vector<unordered_map<int, bool>> m(nums.size());
	return helper(nums, 0, sum, m);
}



int main() {
	vector<int>nums = {1, 5, 11, 5};
	if(canPartition(nums)) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl; 
	}
	return 0;
}