#include<bits/stdc++.h>
using namespace std;

/*
	Approach 1 - Iterative
	Time - O(N ^ 2);
	Space - O(1);
*/ 

/*
	Approach 2 - Dynamic Programming
*/ 

vector<int> getPalindromeLength(string str, int left, int right) {
	while(left >= 0 && right < str.size()) {
		if(str[left] == str[right]) {
			left--;
			right++;
		}else{
			break;
		}
	}
	return vector<int>{left + 1, right};
}

string longestPalindromicSubString(string str) {
	vector<int>longest = {0, 1};

	for(int i = 1; i < str.size(); i++) {
		vector<int> odd = getPalindromeLength(str, i - 1, i + 1);
		vector<int> even = getPalindromeLength(str, i - 1, i);

		vector<int> currentLongest = odd[1] - odd[0] > even[1] - even[0] ? odd : even;
		longest = currentLongest[1] - currentLongest[0] > longest[1] - longest[0] ? currentLongest : longest;
	}

	return str.substr(longest[0], longest[1] - longest[0]);
}

int main() {
	string s = "aaaabbaa";
	cout << longestPalindromicSubString(s);
	return 0;
}
