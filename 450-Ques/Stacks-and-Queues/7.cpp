#include<bits/stdc++.h>
using namespace std;

string reverse(string str) {
	stack<char>s;
	string res;
	
	for(char x : str) s.push(x);

	while(!s.empty()) {
		res += s.top();
		s.pop();
	}

	return res;
}
 
int main() {
	string str = "Hello world";
	cout << reverse(str) << endl;
	return 0;	
}
