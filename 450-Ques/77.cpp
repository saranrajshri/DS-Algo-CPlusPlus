#include<bits/stdc++.h>
using namespace std;

/*
	Naive Approach 
	1. remove the last charecter and check if the string is a palindrome.
	2. increment the count;
	
	Time - O(N ^ 2);
	Space - O(1);
*/ 

bool isPalindrome(string str) {
	int left = 0;
	int right = str.size() - 1;

	while(left <= right) {
		if(str[left++] != str[right--]) return false;
	}

	return true;
}

int minAdditions(string str) {
	int count = 0;
	int found = false;

	while(str.size() > 0) {
		if(isPalindrome(str)) {
			found = true;
			break;
		}else{
			count++;

			str.erase(str.begin() + str.size() - 1);
		}
	}

	if(found) return count;

	return -1;
}

int main() {
	string str = "BABABAA";
	cout << minAdditions(str);
	return 0;
}
