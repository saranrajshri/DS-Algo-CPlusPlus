#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Binary Search
	Time - O(log N);
	Space - O(1);
*/ 

int searchInARotatedSortedArray(vector<int>nums, int target) {
	int left = 0;
	int right = nums.size() - 1;

	// Modified Binary Seach To find the Pivot
	while(left < right) {
		int mid = left + (right - left) / 2;
		if(nums[mid] > nums[right]) {
			left = mid + 1;
		}else{
			right = mid;
		}
	}

	int start = left;
	left = 0;
	right = nums.size() - 1;

	// Select the range
	if(target >= nums[start] && target <= nums[right]) {
		left = start;
	}else{
		right = start - 1;
	}


	// Normal binary Search
	while(left <= right) {
		int mid = left +  (right - left) / 2;
		if(nums[mid] == target) return mid;
		else if(nums[mid] < target) left = mid + 1;
		else right = mid - 1;
 	}

 	return -1;
}

int main() {
	vector<int>nums = {4,5,6,7,0,1,2};
	int target = 0;

	cout << searchInARotatedSortedArray(nums, target);
	return 0;
}
