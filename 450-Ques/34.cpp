#include<bits/stdc++.h>
using namespace std;

/*
	https://www.geeksforgeeks.org/find-minimum-number-of-merge-operations-to-make-an-array-palindrome/
	
	Approach- Two Pointers; 
	1. Initialize left pointer to the start and right pointer to the end;
	2. If both the elements are same, then left++ and right--
	3. If arr[left] > arr[right], 
		Then merge the right tail
	4. else:
		Merge the left tail
	
	Time - O(N);
	Space - O(1);

*/ 

int minOperations(vector<int>arr) {
	int ans = 0;
	int left = 0;
	int right = arr.size() - 1;

	while(left <= right) {
		if(arr[left] == arr[right]) {
			left++;
			right--;
		}
		else if(arr[left] > arr[right]) {
			right--;
			arr[right] = arr[right] + arr[right + 1];
			ans++;
		}else{
			left++;
			arr[left] = arr[left] + arr[left - 1];
			ans++;
		}
	}

	return ans;
}


int main() {
	vector<int>arr = {3, 2, 3, 5};
	cout << minOperations(arr);
	return 0;
}