#include<bits/stdc++.h>
using namespace std;

int isPalindrome(string s, int left, int right) {
	int count = 0;
	while(left >= 0 && right < s.size() && s[left] == s[right]) {
		left--;
		right++;
		count++;
	}

	return count;
}

int palindromicSubStrings(string s) {
	int res = 0;

	for(int i = 0; i < s.size(); i++) {
		res += isPalindrome(s, i, i);

		if(i + 1 < s.size()) {
			res += isPalindrome(s, i, i + 1);
		}
	}

	return res;
}

int main() {
	string s = "aab";
	cout << palindromicSubStrings(s);
	return 0;
}