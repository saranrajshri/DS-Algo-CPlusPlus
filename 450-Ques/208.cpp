#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int left, int right) {
	while(str[left++] != str[right--]) {
		return false;
	}
	return true;
}

void helper(string str, vector<string> currentPath, int startIndex, vector<vector<string>> &res) {
	if(startIndex >= str.size()) {
		res.push_back(currentPath);
		return;
	}

	for(int i = startIndex; i < str.size(); i++) {
		if(isPalindrome(str, startIndex, i)) {
			currentPath.push_back(str.substr(startIndex, i - startIndex + 1));

			helper(str, currentPath, i + 1, res);

			currentPath.pop_back();
		}
	}
}

vector<vector<string>> printAllPalindromicSubStringsCuts(string str){
	vector<vector<string>> res;
	vector<string> currentPath;

	helper(str, currentPath, 0, res);

	return res;
}

int main() {
	string str = "nitin";
	vector<vector<string>> res = printAllPalindromicSubStringsCuts(str);	
	for(vector<string> arr : res) {
		for(string x : arr) {
			cout << x << " ";
		}
		cout << endl;
	}
	return 0;
}