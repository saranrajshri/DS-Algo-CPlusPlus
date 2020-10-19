#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Two pointers
*/ 

int minSwap(vector<int>arr, int k) {
	int count = 0;
	for(int x : arr) {
		if(x <= k) count++; 
	}

	int bad = 0;
	for(int x : arr) {
		if(x > k) bad++
	}

	int ans = bad;

	for(int i = 0, j = count; j < arr.size(); i++, j++) {
		if(arr[i] > k) bad--;
		if(arr[j] > k) bad++;

		ans = min(ans, bad);
	}

	return ans;
}

int main() {
	vector<int>arr = {2, 1, 5, 6, 3};
	int k = 3;
	cout << minSwap(arr, k);
	return 0;
}