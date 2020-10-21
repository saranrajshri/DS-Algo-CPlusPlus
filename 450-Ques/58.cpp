#include<bits/stdc++.h>
using namespace std;


/*
	Approach - Counter Variable
	Time - O(N);
	Space - O(1);
*/ 

int splitStrings(string s) {
	int ans = 0;
	int zeroCount = 0;
	int oneCount = 0;

	vector<string>res;

	for(char c : s) {
		if(c == '0') zeroCount++;
		else if(c == '1') oneCount++;
		
		if(zeroCount == oneCount) ans++;
	}

	if(zeroCount != oneCount) return -1;

	return ans;
}

int main() {
	string s = "0100110101";
	cout << splitStrings(s);

	return 0;
}
