#include<bits/stdc++.h>
using namespace std;

int solve(string s) {
	unordered_map<char, int>m;
	int start = -1;
	int maxLength = 0;

	for(int i = 0; i < s.size(); i++) {
		if(m[s[i]] > start) {
			start = max(m[s[i]], start);
		}

		m[s[i]] = i;
		maxLength =  max(maxLength, i - start);
	}

	return maxLength;
}
	
int main() {
	string s = "abcabcbb";
	cout << solve(s);


	return 0;
}
