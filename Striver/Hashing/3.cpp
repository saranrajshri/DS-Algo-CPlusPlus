#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr) {
	int ans = 0;
	unordered_set<int> s(arr.begin(), arr.end());

	for(int i = 0; i < arr.size(); i++) {
		if(s.find(arr[i] - 1) == s.end()) {
			
			int currentNum = arr[i];
			int streak = 1;

			while(s.find(currentNum + 1) != s.end()) {
				streak++;
				currentNum++;
			}

			ans = max(ans, streak);
		}
	}

	return ans;
}

int main() {
	vector<int>arr = {1, 9, 3, 10, 4, 20, 2};
	cout << solve(arr);
	return 0;	
}

