#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Iterative run time frequency count;
	Time - O(N ^ 2);
	Space - O(1);
*/ 

string countAndSay(int n) {
	string res = "1";
	while(--n) {
		string currentString = "";
		for(int i = 0; i < res.size(); i++) {
			int count = 1;

			while((i + 1 < res.size()) && (res[i] == res[i + 1])) {
				count++;
				i++;
			}
			currentString += to_string(count) + res[i];
		}
		res = currentString;
	}
	return res;
}

int main() {
	int n = 2;
	cout << countAndSay(n);	
	return 0;
}