#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Linear Search 
	Time - O(N);
	Space - O(1);
*/		

/*
	Approach - Binary Search
	Time - O(log N);
	Space - O(1);
*/ 

int valueEqualToIndex(vector<int>arr) {
	for(int i = 0; i < arr.size(); i++) {
		if(arr[i] == i + 1) return arr[i];
	}

	return -1;
}

int main() {
	vector<int>arr = {15, 2, 45, 12, 7};
	cout << valueEqualToIndex(arr);
	return 0;
}