#include<bits/stdc++.h>
using namespace std;


/*
	Time - O(N);
	Space - O(1);
*/ 


vector<int> productExceptSelf(vector<int> nums) {
	vector<int>res(nums.size(), 1);
	int fromBegin = 1;
	int fromEnd = 1;

	for(int i = 0; i < nums.size(); i++) {
		res[i] *= fromBegin;
		fromBegin *=  nums[i];
	}

	for(int i = nums.size() - 1; i >= 0; i--) {
		res[i] *= fromEnd;
		fromEnd *= nums[i];
	}


	return res;
}

int main() {
	vector<int>arr = {1,2,3,4};
	vector<int>res = productExceptSelf(arr);

	for(int x : res) cout << x << " ";
	return 0;
}
