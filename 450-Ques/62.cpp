#include<bits/stdc++.h>
using namespace std;


/*
	Approach - Using Stack 
	Time - O(N);
	Space - O(N);
*/ 


bool isBalanced(string str) {
	stack<char>s;
	for(char c : str) {
		switch(c) {
			case '{' : s.push('}'); break;
			case '(' : s.push(')'); break;
			case '[' : s.push(']'); break;
			default:
				if(s.empty() || s.top() != c) return false;
				else s.pop();
		}
	}

	return s.empty();
}

int main() {
	string s = "{([)}";
	if(isBalanced(s)) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}

	return 0;
}
