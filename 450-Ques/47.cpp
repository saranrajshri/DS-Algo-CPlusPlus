#include<bits/stdc++.h>
using namespace std;


/*
	Approach - Two pointers;
	
	Time - O(N);
	Space - O(1)
*/ 

void swap(string &str, int left, int right) {
	char temp = str[left];
	str[left] = str[right];
	str[right] = temp;
}

string reverseString(string str) {
	int left = 0;
	int right = str.size() - 1;

	while(left <= right) {
		swap(str, left++, right--);
	}

	return str;
}

int main() {
	string s = "Hello World";
	cout << reverseString(s);
	return 0;
}