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



int main() {
	vector<int>arr = {1, 0, 1, 2, 2, 1, 0};
	sort(arr);

	for(int x : arr) {
		cout << x << " ";
	}
	return 0;
}