#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Sort and three pointers
	Time - O(N ^ 2);
	Space - O(1);
*/ 

vector<vector<int>> threeSum(vector<int>arr, int k) {
	vector<vector<int>>res;

	sort(arr.begin(), arr.end());

	for(int currentIndex = 0; currentIndex < arr.size(); currentIndex++) {
		int left = currentIndex + 1;
		int right = arr.size() - 1;

		while(left < right) {
			int sum = arr[currentIndex] + arr[left] + arr[right];
			if(sum == k) res.push_back(vector<int>{arr[currentIndex], arr[left], arr[right]});
			else if(sum < k) left++;
			else right--; 
		}
	}

	return res;
}

int main() {
	vector<int>arr = {1, 4, 45, 6, 10, 8};
	int k = 13;
	vector<vector<int>>res = threeSum(arr, k);

	for(auto arr : res) {
		for(auto x : arr) cout << x << " ";
		cout << endl;
	}

	return 0;
}