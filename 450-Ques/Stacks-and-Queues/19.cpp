#include<bits/stdc++.h>
using namespace std;

class Stack {
	queue<int> q1, q2;

public:
	void push(int x);
	int pop();
};

void Stack::push(int x) {
	q2.push(x);

	while(!q1.empty()) {
		q2.push(q1.front());
		q1.pop();
	}

	queue<int> tempQ = q1;
	q1 = q2;
	q2 = tempQ;
}

int Stack::pop() {
	if(q1.empty()) return -1;
	
	int topElement = q1.front();
	q1.pop();
	return topElement;		
}

int main() {
	Stack s;
	s.push(20);
	s.push(30);
	s.push(50);
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	return 0;	
}
