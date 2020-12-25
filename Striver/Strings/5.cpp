#include<bits/stdc++.h>
using namespace std;

void computeLPS(string pattern, vector<int>&lps) {
	int len = 0;
	lps[0] = 0;

	int i = 1;

	while(i < pattern.size()) {
		if(pattern[i] == pattern[len]) {
			len++;
			i++;
			lps[i] = len;
		}else{
			if(len != 0) {
				len = lps[len - 1];
			}else{
				lps[i] = 0;
				i++;	
			}
		}
	}
}

vector<int> solve(string str, string pattern) {
	vector<int> lps(pattern.size());
	vector<int> res;

	computeLPS(pattern, lps);

	int i = 0;
	int j = 0;

	while(i < str.size() && j < pattern.size()) {
		if(j == pattern.size() - 1) {
			res.push_back(i - j); 
		}	

		if(str[i] == pattern[j]) {
			i++;
			j++;
		}else{
			if(j != 0) {
				j = lps[j - 1];
			}else{
				i++;
			}
		}
	}

	return res;
}

int main() {
	string str = "ABABDABACDABABCABAB";
	string pattern = "ABABCABAB";

	vector<int> res = solve(str, pattern);

	for(int x : res) cout << x << " ";
	return 0;	
}
