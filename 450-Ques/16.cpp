#include<bits/stdc++.h>
using namespace std;

/*
	Count Inversions
	https://www.geeksforgeeks.org/counting-inversions/
*/	

/*
	Brute Force Approach
	Time - 0(N^2);
	Space - O(1);
*/ 

/*
	Optimal Approach - Merge Sort
	Time - (N Log N);
	Space - O(N);
*/ 

int countInversions(vector<int>arr) {
	int count = 0;

	for(int i = 0; i < arr.size() - 1; i++) {
		for(int j = i + 1; j < arr.size(); j++) {
			if(arr[j] > arr[i]) count++;
		}
	}

	return count;
}

int main() {
	vector<int>arr = {1, 20, 6, 4, 5 };
	cout  << countInversions(arr);
	return 0;
}