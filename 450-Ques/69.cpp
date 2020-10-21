#include<bits/stdc++.h>
using namespace std;
	
/*	
	Approach - Sort;
	Time - O(N ^ 2);
	Space - O(1);
*/		

string longestCommonPrefix(vector<string> words) {
	sort(words.begin(), words.end());

	int n = words.size();
	string s1 = words[0];
	string s2 = words[n - 1];
	string ans = "";

	fr(int i = 0; i < s1.size(); i++) {
		if(s1[i] == s2[i]) ans += s1[i];
		else break;
	}

	return ans;
}

/*
	 Little Optimized Code;
	 Time - O(N Log N); Bcoz of Sorting
	 Space - O(1);
*/
 
string longestCommonPrefix(vector<string> words) {
	sort(words.begin(), words.end());

	int n = words.size();
	string s1 = words[0];
	string s2 = words[n - 1];
	int left = 0;
	int right = -1;

	for(int i = 0; i < s1.size(); i++) {
		if(s1[i] == s2[i]) right = i;
		else break;
	}

	return s1.substr(left, right + 1);
}


int main() {
	vector<string> words =  {"flower","flow","flight"};
	cout << longestCommonPrefix(words);
	return 0;
}