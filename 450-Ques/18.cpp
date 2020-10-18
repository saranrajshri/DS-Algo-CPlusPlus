#include<bits/stdc++.h>
using namespace std;


/*
	Approach 1 - Brute Force
	For each element, iterate all the elements in the array and check if their sum is equal to k

	Time - O(N^2);
	Space - O(1);
*/ 
/*
	Approach 2 - Sort and Two Pointers
	Time - O(N log N);
	Space - O(1);
*/ 

/*
	Approach 3 - Hashmap
		
	1. Store the frequency of all element
	2. Iterate through the array
	3. Find the number of occurences of the currentElement, add it to the `count`
	4. If the targe to find is equal to the K, then decrement the `count`
	
	Time - O(N);
	Space - (N);


*/ 

int twoSumPairs(vector<int>arr, int k) {
	unordered_map<int, int>m;

	// Store the frequency of all elements
	for(int x : arr) m[x]++;

	int count = 0;

	for(int i = 0; i < arr.size(); i++) {
		int targetToFind = k - arr[i];

		count += m[targetToFind];

		if(targetToFind == arr[i]) count--;

	}
	return count / 2;
}

int main() {
	vector<int>arr = {1, 5, 7, -1, 5};
	int k = 6;
	cout << twoSumPairs(arr, k);

	return 0;
}