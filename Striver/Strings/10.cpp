#include<bits/stdc++.h>
using namespace std;

void computeLPS(string str, vector<int>&lps) {
	int len = 0;
	int i = 1;

	while(i < str.size()) {
		if(str[i] == str[len]) {
			i++;
			len++;
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

bool solve(string str) {
	vector<int> lps(str.size());

	computeLPS(str, lps);

	int subStringLen = lps[str.size() - 1];
	int n = str.size();

	return n % (n - subStringLen);
}

int main() {
	string str = "GEEKGEEK";
	if(solve(str)) cout << "Yes" << endl;
	else cout << "No" << endl;
	return 0;	
}
