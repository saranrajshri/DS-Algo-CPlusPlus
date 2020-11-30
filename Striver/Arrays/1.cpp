#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr) {
	int slow = 0, fast = 0;

	while(1) {
		fast = arr[arr[fast]];
		slow = arr[slow];

		if(fast == slow) break;
	}

	int runner = 0;

	while(1) {
		slow = arr[slow];
		runner = arr[runner];

		if(slow == runner) break;
	}

	return slow;
}

int main() {
	vector<int>arr = {1,3,4,2,2};
	cout << solve(arr);
	return 0;	
}

