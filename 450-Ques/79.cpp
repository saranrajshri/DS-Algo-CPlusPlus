#include<bits/stdc++.h>
using namespace std;


/*
	Iterative Approach;
	Time - O(N);
	Space - O(1);
*/ 

string removeAdjacentElements(string s) {
	string res = "";	

	if(s.size() == 0) return s;

	res += s[0];

	for(int i = 1; i < s.size(); i++) {
		if(s[i] != s[i - 1]) res += s[i]; 
	}

	return res;
}

int main() {
	string s = "aaabbbaaccdd";
	cout << removeAdjacentElements(s);
	return 0;
}