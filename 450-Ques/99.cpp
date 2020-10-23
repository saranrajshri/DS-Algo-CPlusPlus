#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Sort + Three pointers
	Time - O(N ^ 2);
	Space - O(1);	
*/ 


int threeSum(vector<int>arr, int target) {
	int count = 0;

	sort(arr.begin(), arr.end());

	for(int i = 0; i < arr.size(); i++) {
		int left = i + 1;
		int right = arr.size() - 1;

		while(left < right) {
			int sum = arr[left] + arr[right] + arr[i];
			if(sum >= target) {
				right--;
			}
			else {
				left++;
				count += (right - left);

			}
		}
	}

	return count;
}

int main() {
	vector<int> arr = {-2, 0, 1, 3};
	int target = 2;
	cout << threeSum(arr, target);
	return 0;
}