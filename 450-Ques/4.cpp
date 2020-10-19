#include<bits/stdc++.h>
using namespace std;

// Sort the array without using sort function
// time - O(N), Space - O(1);

void sort(vector<int>&arr) {
	int onesCount = 0, twosCount = 0, zerosCount = 0;

	// Count the frequency of 0, 1, 2;
	for(int x : arr) {
		if(x == 0) zerosCount++;
		else if(x == 1) onesCount++;
		else twosCount++;
	}

	int index = 0;		

	// Traverse the array
	while(index < arr.size()) {
		// First fill the elements to 0 until zerosCount becomes 0
		while(zerosCount--) {
			arr[index] = 0;
			index++;
		}

		// First fill the elements to 1 until oneCount becomes 0
		while(onesCount--) {
			arr[index] = 1;
			index++;
		}
		
		// First fill the elements to 2 until oneCount becomes 0
		while(twosCount--) {
			arr[index] = 2;
			index++;
		}
	}
}

/*
	Approach 2 - Dutch National Flag Algorithm
	1. Initialize three pointers low = mid = 0, high = n - 1;
	2. Traverse the array from the left;
	3. If the mid element is zero, move it to the left half, low++, mid++;
	4. If the mid element is 1, keep the element as it is and shrink the unknown range;
	5. If the mid element is 2, move it to the right half;
	
	Similar to QuickSort 

	Time - O(N);
	Space - O(1);
*/ 

void swap(vector<int>&arr, int left, int right) {
	int temp = arr[left];
	arr[left] = arr[right];
	arr[right] = temp;
}

void sort(vector<int>&arr) {
	int low = 0, mid = 0;
	int high = arr.size() - 1;

	while(mid <= high) {
		switch(arr[mid]) {
			case 0:
				swap(arr, low++, mid++);
				break;
			case 1:
				mid++;
				break;
			case 2:
				swap(arr, mid, high--);
				break;
		}
	}
}

int main() {
	vector<int>arr = {1, 0, 1, 2, 2, 1, 0};
	sort(arr);

	for(int x : arr) {
		cout << x << " ";
	}
	return 0;
}