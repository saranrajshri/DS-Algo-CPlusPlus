#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Simple
	Find all the combinations
	Count the unmatching chars;

	Time - O(n);
	Space - O(1);
*/ 

int  minFlipsHelper(string s, char expectedChar) {
	int flipCount = 0;

	for(int i = 0; i < s.size(); i++) {
		if(s[i] != expectedChar) flipCount++;
		expectedChar = expectedChar == '0' ? '1' : '0';
	}

	return flipCount;
}

int minFlips(string s) {
	return min(minFlipsHelper(s, '0'), minFlipsHelper(s, '1'));
}

int main() {
	string s = "0001010111";
	cout << minFlips(s);
	return 0;
}
