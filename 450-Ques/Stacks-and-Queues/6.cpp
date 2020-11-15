#include<bits/stdc++.h>
using namespace std;

/*
	Time - O(n);
	Space - O(n);
*/

bool isBalanced(string str) {
	stack<char> s;

	for(char c : str) {
		switch(c) {
			case '(':
					s.push(')');
					break;
			case '[':
					s.push(']');
					break;
		    case '{':
					s.push('}');
					break;
			default:
					if(s.empty() || s.top() != c) return false;
					else s.pop();
		}
	} 

	return s.empty();
}

int main() {
	string str = "(({{}}))";
	if(isBalanced(str)) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;	
}
