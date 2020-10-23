#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Two Pointers
	Time - O(N);
	Space - O(1);
*/ 


vector<int> mergeSortedArrays(vector<int> nums1, vector<int> nums2, int m, int n) {
	int i = m - 1;
	int j = n - 1;
	int k = m + n - 1;

	while(i < nums1.size() && j < nums2.size()) {
		if(nums2[j] > nums1[i]) {
			nums1[k] = nums2[j];
			j--;
			k--; 
		}else{
			nums1[k] = nums1[i];
			i--;
			k--;
		}
	}

	while(j < nums2.size()) {
		nums1[k] = nums2[j];
		j--;
		k--;
	}
	return nums1;
}

int main() {
	vector<int> nums1 = {1, 2, 3, 0, 0, 0};
	vector<int> nums2 = {2, 5, 6};
	int m = 3;
	int n = 3;

	vector<int> res = mergeSortedArrays(nums1, nums2, m, n);

	for(int x : res) cout << x << " ";
	return 0;
}