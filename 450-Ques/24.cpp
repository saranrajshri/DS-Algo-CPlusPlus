#include<bits/stdc++.h>
using namespace std;


/*
	Approach - Hash Set;
	
	1. Create a hashset and insert all the numbers in it;
	2. Traverse through the array and check currentNum - 1 is in the set or not;
	3. If the currentNum - 1 is in the set, we know that currentNum is not the starting num of the sequence
	4. We do this repeatedly and calculate the length on the fly.

	Time - O(N)
	Space - O(N)
*/ 


int longestConsecutiveSubSequence(vector<int>arr) {
	unordered_set<int>s;
	int longestStreak = INT_MIN;
	for(int x : arr) {
		s.insert(x);
	}


	for(int i = 0; i < arr.size(); i++) {
		int streak = 1;
		int currentNum = arr[i];
		while(s.find(currentNum - 1) != s.end()) {
			streak++;
			currentNum--;
		}	

		longestStreak = max(longestStreak, streak);
	}
	return longestStreak;
}

int main() {
	vector<int> arr = {1, 9, 3, 10, 4, 20, 2};
	cout << longestConsecutiveSubSequence(arr);
	return 0;
}