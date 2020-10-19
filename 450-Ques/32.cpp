#include<bits/stdc++.h>
using namespace std;

/*
	https://www.geeksforgeeks.org/three-way-partitioning-of-an-array-around-a-given-range/
	
	Given an array and a range [lowVal, highVal], partition the array around the range such that array is divided in three parts.
	1) All elements smaller than lowVal come first.
	2) All elements in range lowVal to highVVal come next.
	3) All elements greater than highVVal appear in the end.
	
	
	Approach - Dutch National Flag Algorithm
*/ 

void swap(vector<int>&arr, int left, int right) {
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}

vector<int>threeWayPartition(vector<int>arr, int lowVal, int highVal) {
	int left = 0;
	int right = arr.size() - 1;
	int mid = 0;

	while(mid <= right) {
		if(arr[mid] < lowVal) {
			swap(arr, left++, mid++);
		}else if(arr[mid] > highVal) {
			swap(arr, mid, right--);
		}else{
			mid++;
		}
	}
	return arr;
}

int main() {
	vector<int>arr = {1, 14, 5, 20, 4, 2, 54, 20, 87, 98, 3, 1, 32};

	vector<int>res = threeWayPartition(arr, 10, 20);

	for(int x : res) cout << x << " ";
	return 0;
}