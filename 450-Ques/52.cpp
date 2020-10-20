#include<bits/stdc++.h>
using namespace std;

/*
	https://www.programiz.com/java-programming/examples/check-valid-shuffle-of-strings
	
	Approach - Three Pointers
	Time - O(N);
	Space - O(1);
*/ 

bool shuffleCheck(string s1, string s2, string res) {
	int i = 0, j = 0, k = 0;

	while(k != res.size()) {
		if(i < s1.size() && s1[i] == res[k]) i++;
		else if(j < s2.size() && s2[j] == res[k]) j++;
		else return false;

		k++;
	}

	if(i < s1.size() || j < s2.size()) return false;
	return true;
}

int main() {
	string s1 = "XY";
	string s2 = "12";

	vector<string>results = {"1XY2", "Y12X"};

	for(string s: results) {
		if(shuffleCheck(s1, s2, s)) {
			cout << "Yes" << endl;
		}else{
			cout << "No" << endl;
		}
	}
	return 0;
}
