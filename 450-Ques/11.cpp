#include<bits/stdc++.h>
using namespace std;

/*
	Approach 1 - Use HashMap
*/
// int duplicateNumber(vector<int>arr) {
// 	unordered_map<int, int> m;

// 	for(int x : arr) {
// 		if(m.find(x) == m.end()) {
// 			m[x] = x;
// 		}else{
// 			return x;
// 		}
// 	}

// 	return -1;
// }

/*
	Approach - 2
	Tortoise and hare approach
	Time - O(N), Space - O(1)
*/ 
int duplicateNumber(vector<int>arr) {
	int fast = 0;
	int slow = 0;

	while(1) {
		slow = arr[slow];
		fast = arr[arr[fast]];	
		if(slow == fast) break;
	}

	int runner = 0;

	while(1){
		slow = arr[slow];
		runner = arr[runner];
		if(slow == runner) break;
	}	

	return runner;

}

int main() {
	vector<int>arr = {1, 2, 3, 4, 3, 6};
	cout << duplicateNumber(arr);
	return 0;
}