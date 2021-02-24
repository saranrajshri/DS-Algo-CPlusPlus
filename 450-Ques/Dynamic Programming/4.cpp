#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> mem;

bool isSubSetSum(vector<int> nums, int n, int index, int sum) {
	if(sum == 0) return true;
	if(index >= n || sum < 0) return false;

	if(mem[index][sum] != -1) return mem[index][sum];

	mem[index][sum] = isSubSetSum(nums, n, index + 1, sum - nums[index]) || isSubSetSum(nums, n, index + 1, sum);

	return mem[index][sum];
}

bool solve(vector<int> nums) {
	int sum = accumulate(nums.begin(), nums.end(), 0);
	if(sum & 1) return false;

	sum = sum / 2;

	mem.clear();
	mem.resize(nums.size() + 1, vector<int>(sum / 2,  -1));

	return isSubSetSum(nums, nums.size(), 0, sum);
}

int main() {
	vector<int> nums = {1, 5, 5 ,11};
	if(solve(nums)) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;	
}
