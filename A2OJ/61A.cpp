#include<bits/stdc++.h>
using namespace std;

int main() {
	string str1, str2;
	cin >> str1 >> str2;

	string res;

	for(int i = 0; i < str1.size(); i++) {
		if(str1[i] == str2[i]) res += '0';
		else res += '1';
	}

	cout << res << endl;

	return 0;	
}
