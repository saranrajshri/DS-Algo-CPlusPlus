#include "bits/stdc++.h"
#define int long long
using namespace std;

stack<int> s;

void insertAtCorrectPosition(int x) {
	if(s.empty() || x < s.top()) {
		s.push(x);
		return;
	}

	int top = s.top();
	s.pop();

	insertAtCorrectPosition(x);
	s.push(top);
}

void sort() {
	if(s.empty()) return;

	int temp = s.top();
	s.pop();

	sort();

	insertAtCorrectPosition(temp);
}



int32_t main() {
	s.push(9);
	s.push(2);
	s.push(7);
	s.push(4);
	s.push(6);
	sort();

	while(!s.empty()) {
		cout << s.top() << " "; 
		s.pop();
	}
	return 0;	
}
