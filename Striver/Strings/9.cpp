#include<bits/stdc++.h>
using namespace std;

void computeLPS(string newString, vector<int>&lps) {
	int i = 1;
	int len = 0;
	lps[0] = 0;

	while(i < newString.size()) {
		if(newString[i] == newString[len]) {
			i++;
			len++;
			lps[i] = len;
		}else{
			if(len != 0) {
				len = lps[i - 1];
			}else{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int solve(string str) {
	string reversedString = str;

	reverse(reversedString.begin(), reversedString.end());

	string newString = str + "$" + reversedString;

	vector<int> lps(newString.size());
	computeLPS(newString, lps);

	return str.size() - lps.back();
}

int main() {
	string str = "AACECAAAA";
	cout << solve(str);
	return 0;	
}
