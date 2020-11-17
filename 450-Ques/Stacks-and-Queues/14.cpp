#include<bits/stdc++.h>
using namespace std;


stack<int> sort(stack<int>&s) {
	stack<int> tempStack;

	while(!s.empty()) {
		int tempElement = s.top();
		s.pop();

		while(!tempStack.empty() && tempStack.top() > tempElement) {
			s.push(tempStack.top());
			tempStack.pop();
		}

		tempStack.push(tempElement);
	}

	return tempStack;
}

void solve() {
	stack<int>s;

	s.push(34);
    s.push(3);
    s.push(31);
    s.push(98);
    s.push(92);
    s.push(23);

    stack<int> newStack = sort(s);

    while(!newStack.empty()) {
    	cout << newStack.top() << " ";
    	newStack.pop();
    }
}


int main() {
	solve();
	return 0;	
}
