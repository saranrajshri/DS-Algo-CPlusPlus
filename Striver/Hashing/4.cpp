#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr) {
	unordered_map<int, int>s;

	int prefix = 0;
	int maxLen = 0;

	for(int i = 0; arr.size(); i++) {
		prefix += arr[i];

		if(arr[i] == 0 && maxLen == 0) {
			maxLen = 1;
		} 
		if(prefix == 0) {
			maxLen = i + 1;
		}

		if(s.find(prefix) != s.end()) {
			maxLen = max(maxLen, i - s[prefix]);
		}else{
			s[prefix] = i;
		}
	}

	return maxLen;
}

int main() {
	vector<int>arr = {15, -2, 2, -8, 1, 7, 10, 23};
	cout << solve(arr);
	return 0;	
}
