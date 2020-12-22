#include<bits/stdc++.h>
using namespace std;

string solve(vector<string> arr) {
	string res = "";
	sort(arr.begin(), arr.end());

	string strOne = arr[0];
	string strTwo = arr[arr.size() - 1];

	for(int i = 0; i < strOne.size(); i++) {
		if(strOne[i] == strTwo[i]) res += strOne[i];
		else break;
	}


	return res;
}

int main() {
	vector<string> arr = {"flower","flow","flight"};
	cout << solve(arr);
	return 0;	
}
