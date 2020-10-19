#include<bits/stdc++.h>
using namespace std;

int median(vector<int>arr, int n)
{
    if (n % 2 == 0)
        return (arr[n / 2] + arr[n / 2 - 1]) / 2;
    else
        return arr[n / 2];
}

double getMedian(vector<int>nums1, vector<int>nums2) {
	int n = nums1.size();

	// Base Cases
	if(n <= 0) return -1;
	else if(n == 1) return (nums1[0] + nums2[0]) / 2.0;
	else if(n == 2) {
		return max(nums1[0] + nums2[0], nums1[1] + nums2[1]) / 2.0;
	} 

	/*	
		Now we have an array of length > 2;
		find the median of nums1 and nums2;

	*/ 

	double median1 = calculateMedian(nums1);
	double median2 = calculateMedian(nums2);

	if(median1 == median2) return median1;

	/*
		if median1 < median2, we know that the median will be at nums1[mid...n];
	*/ 		
	if(median1 < median2) {
		if(n % 2 == 0) {
			return getMedian(nums1.begin() + n / 2 - 1, nums2, n - n / 2 + 1);
		}else{
			return getMedian(nums1.begin() + n / 2, nums2, n - n / 2);
		}
	}else{
		if(n % 2 == 0) {
			return getMedian(nums2.begin() + n / 2 - 1, nums1, n - n / 2 + 1);
		}else{
			return getMedian(nums2.begin() + n / 2, nums1, n - n / 2);
		}
	}

}

int main() {
	vector<int>nums1 = {1, 12, 15, 26, 38};
    vector<int>nums2 = {2, 13, 17, 30, 45};
 	
 	cout << getMedian(nums1, nums2);
	return 0;
}