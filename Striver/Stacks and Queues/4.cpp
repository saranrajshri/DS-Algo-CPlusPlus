#include<bits/stdc++.h>
using namespace std;

bool solve(string str) {
	stack<char>s;

	for(int c : str) {
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
	if(solve(str)) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl; 
	}
	return 0;	
}
