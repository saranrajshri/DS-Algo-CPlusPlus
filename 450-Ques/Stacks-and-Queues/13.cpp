#include<bits/stdc++.h>
using namespace std;

stack<int> s;

void insertAtEnd(int x) {
	if(s.empty()) {
		s.push(x);
		return;
	}

	int topElement = s.top();
	s.pop();

	insertAtEnd(x);

	s.push(topElement);
}

void reverse() {
	if(s.size() == 0) return;

	int topElement = s.top();
	s.pop();

	insertAtEnd(topElement);

}

void solve() {

	s.push(1);
	s.push(2);
	s.push(2);
	s.push(3);
	s.push(4);


	reverse();

	while(!s.empty()) {
		cout << s.top() << " ";
		s.pop();
	}
}

int main() {
	solve();
	return 0;	
}
