#include<bits/stdc++.h>
using namespace std;

int solve(string str) {
	stack<char>s;
	int length = 0;

	for(char c : str) {
		switch(c) {
			case '(':
				s.push(')');
				break;
			default:
				if(s.empty() || s.top() != c) continue;
				else{
					s.pop();
					length += 2;
				}
		}
	}

	return length;
}

int main() {
	string str = "()(())(";
	cout << solve(str) << endl;
	return 0;	
}
