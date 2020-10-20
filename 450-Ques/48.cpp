#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Two Pointers
	Time - O(N);
	Space - O(1);
*/ 


bool isPalindrome(string s) {
	int left = 0;
	int right = s.size() - 1;

	while(left <= right) {
		if(s[left++] != s[right--]) return false;
	}

	return true;
}

int main() {
	string s = "madam";
	if(isPalindrome(s)) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
 	}
	return 0;
}