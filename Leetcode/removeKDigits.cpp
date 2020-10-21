#include<bits/stdc++.h>
using namespace std;

string removeKDigits(string s, int k) {
	string ans = "";

	for(char c : s) {
		while(ans.size() > 0 && ans.back() > c && k) {
			ans.pop_back();
			k--;
		}

		if(ans.size() > 0 || c != '0') ans.push_back(c);
	}

	while(ans.size() > 0 && k--) ans.pop_back();

	return ans;
}

int main() {
	string s  = "1233525";
	int k = 3;

	cout << removeKDigits(s, k);
	
	return 0;
}