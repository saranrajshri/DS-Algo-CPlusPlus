#include<bits/stdc++.h>
using namespace std;


/*
	Approach 
	
	1. (Iterate backwards) Find the index which seperates the array into ascending and descending, mark it as K;
	2. Then, find the number whick is greater than K;
	3. Swap the elements;
	4. Reverse the array from arr.begin() + K to arr.end(); 

	One Edge case
	1. If the value of k is less than 0;
	It means that the array is in ascending order,
	So we can simply reverse the array and return it.

	Time - O(N);
	Space - O(1);
*/ 

void swap(vector<int>&arr, int left, int right) {
	int temp = arr[right];
	arr[right] = arr[left];
	arr[left] = temp;	
}

vector<int>nextPermutation(vector<int>arr) {
	int k, l;
	int n = arr.size();

	for(k = n - 2; k >= 0; k--) {
		if(arr[k] < arr[k + 1]) break;
	}

	// Edge case
	if(k < 0) {
		reverse(arr.begin(), arr.end());
	}else{
		for(l = n - 1; l > k; l--) {
			if(arr[l] > arr[k]) break;
		}

		swap(arr, l, k);
		reverse(arr.begin() + k, arr.end());
	}
	return arr;
}

int main() {
	vector<int>arr = {1, 5, 8, 9, 2};	
	vector<int>res = nextPermutation(arr);

	for(auto x : res) {
		cout << x << " ";
	}

	return 0;
}


