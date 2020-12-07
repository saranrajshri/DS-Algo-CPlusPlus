#include<bits/stdc++.h>
using namespace std;

int solve(string str) {
	map<char, int> m;
	int start = -1;
	int maxLen = 0;

	for(int i = 0; i < str.size(); i++) {
		if(m.count(str[i]) != 0) {
			start = max(start, m[str[i]]);
		}
		m[str[i]] = i;
		maxLen = max(maxLen, i - start);
	}

	return maxLen;
}

int main() {
	string str = "abcabcbb";
	cout << solve(str);
	return 0;	
}

