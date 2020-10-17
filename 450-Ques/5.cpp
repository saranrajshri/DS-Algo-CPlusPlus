#include<bits/stdc++.h>
using namespace std;

/*
	Approach : Two pointers
	Assign two pointers, one to the front of the array, and another to the end of the array;
	
	When the two pointers overlap, break the loop

	1. Move the right pointer till it reaches a negatige number;
	2. When the left pointer points to a positive number, then swap their indexes and increment left and decrement right;
	3. Else move the left pointer  

	Time - O(N)
	Space - O(1)
*/

void swap(vector<int>&arr, int leftIndex, int rightIndex) {
	int temp = arr[leftIndex];
	arr[leftIndex] = arr[rightIndex];
	arr[rightIndex] = temp;
}


void moveNegativeNumbers(vector<int>&arr) {
	int left = 0;
	int right = arr.size() - 1;

	while(left <= right) {
		// Move the right pointer to a negative number
		while(right >= 0 && arr[right] >= 0) right--;
		if(arr[left] >= 0 && arr[right] < 0) {
			swap(arr, left, right);
			left++;
			right--;
		}else{
			left++;
		}
	}
}

int main() {
	vector<int>arr = {12, 11, -13, -5, 6, -7, 5, -3, -6};
	moveNegativeNumbers(arr);

	for(int x : arr) { 
		cout << x << " ";
	}
	return 0;
}