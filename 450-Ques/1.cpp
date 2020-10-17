#include<bits/stdc++.h>
using namespace std;


// Time - O(n);
// Space - O(1);

void swap(vector<int>&arr, int leftIndex, int rightIndex) {
	int temp = arr[rightIndex];
	arr[rightIndex] = arr[leftIndex];
	arr[leftIndex] = temp;
} 

void reverse(vector<int> &arr) {
	int left = 0;
	int right = arr.size() - 1;

	while(left <= right) {
		swap(arr, left, right);
		left++;
		right--;
	}
}


int main() {
	vector<int>arr = {1, 2, 3, 4, 5};
	reverse(arr);

	for(int x :arr) {
		cout << x << " ";
	}
	return 0;

}