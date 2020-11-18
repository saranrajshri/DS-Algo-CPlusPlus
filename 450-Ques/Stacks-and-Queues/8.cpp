#include<bits/stdc++.h>
using namespace std;

stack<pair<int, int>> s;

void push(int val) {
	if(s.empty()) {
		s.push(make_pair(val, val));
	}else{
		int top = s.top().second;
		s.push(make_pair(val, val < top ? val : top));
	}
}


int getMin() {
	if(s.empty()) return -1;
	return s.top().second;	
}

void solve() {
	push(18);
	push(19);
	push(29);
	push(15);
	push(16);w
	cout << getMin() << endl;
}

int main() {
	solve();
	return 0;	
}
