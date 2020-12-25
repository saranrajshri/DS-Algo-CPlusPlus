#include<bits/stdc++.h>
using namespace std;

string solve(int n) {
	string res = "1";

	while(--n) {
		string current = "";

		for(int i = 0; i < res.size(); i++) {
			int count = 1;
			while(i + 1 < res.size() && res[i] == res[i + 1]) {
				count++;
				i++;
			}
			current += to_string(count);
			current += res[i];
		}

		res = current;
	}

	return res;
}

int main() {
	int n = 4;
	cout << solve(n);
	return 0;	
}
