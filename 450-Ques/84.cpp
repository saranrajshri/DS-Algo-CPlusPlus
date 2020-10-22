#include<bits/stdc++.h>
using namespace std;

/*
	Time - O(N);
	Space - O(N);
*/ 
bool isIsomorphic(string s1, string s2) {
	vector<int>m1(256, 0);
	vector<int>m2(256, 0);

	int count = 0;
	for(int i = 0; i < s1.size(); i++) {
		if(m1[s1[i]] != m2[s2[i]]) return false;
		else{
			m1[s1[i]] = count;
			m2[s2[i]] = count;
			count++;
		}
	}

	return true;
}

int main() {
	string s1 = "aab";
	string s2 = "xxy";

	if(isIsomorphic(s1, s2)) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}