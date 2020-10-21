#include<bits/stdc++.h>
using namespace std;

/*
	https://www.geeksforgeeks.org/write-a-c-program-to-print-all-permutations-of-a-given-string/
	
	Approach - Backtracking;
	Time - O(n * n!);
	Space - O(n * n!); Call Stack;
*/ 

void swap(string &s, int left, int right) {
	char temp = s[left];
	s[left] = s[right];
	s[right] = temp;
}

void permutationsHelper(string s, int left, int right, vector<string>&res) {
	if(left == right) {
		res.push_back(s);
		return;
	}else{
		for(int i = left; i <= right; i++) {
			swap(s, left, i);

			permutationsHelper(s, left + 1, right, res);

			swap(s, left, i);
		}
	}
}

vector<string> permutations(string s) {
	vector<string>res;
	permutationsHelper(s, 0, s.size() - 1, res);
	return res;
}	

int main() {
	string s = "abc";
	vector<string>res = permutations(s);

	for(string str: res) {
		cout << str << endl;
	}
	return 0;
}
