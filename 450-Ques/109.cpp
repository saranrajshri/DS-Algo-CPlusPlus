#include<bits/stdc++.h>
using namespace std;

/*
	Approch - Two pointers
	Time - O(K);
	Space - O(1);
*/ 

int kthElement(vector<int>nums1, vector<int>nums2, int k) {
	int i = 0, j = 0, KCount = 0;

	while(i < nums1.size() && j < nums2.size()) {
		if(nums1[i] < nums2[j]) {
			KCount++;
			if(KCount == k) return nums1[i];
			i++;
		}else{
			KCount++;
			if(KCount == k) return nums2[j];
			j++;
		}
	}

	while(i < nums1.size()) {
		KCount++;
		if(KCount == k) return nums1[i];
		i++;
	}

	while(j < nums2.size()) {
		KCount++;
		if(KCount == k) return nums2[j];
		j++;
	}

	return -1;
}

int main() {
    vector<int>nums1 = { 2, 3, 6, 7, 9 }; 
    vector<int>nums2 = { 1, 4, 8, 10 }; 
    int k = 5;
	cout << kthElement(nums1, nums2, k);
	return 0;
}