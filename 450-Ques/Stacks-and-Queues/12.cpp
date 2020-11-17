#include<bits/stdc++.h>
using namespace std;

void insertAtEnd(stack<int>&s, int n) {
	if(s.empty()) { 
		s.push(n);
		return;
	}else{
		int topElement = s.top();
		s.pop();
		insertAtEnd(s, n);

		s.push(topElement);
	}
}

void solve(int n) {
	stack<int> s;

	s.push(10);
	s.push(20);
	s.push(30);

	insertAtEnd(s, n);

	while(!s.empty()) {
		cout << s.top() << endl;
		s.pop();
	}
}

int main() {
	solve(50);
	return 0;	
}
