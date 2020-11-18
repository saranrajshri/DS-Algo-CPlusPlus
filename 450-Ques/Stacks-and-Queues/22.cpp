#include<bits/stdc++.h>
using namespace std;

class Queue {
	stack<int> s1;
	stack<int> s2;
public:
	void push(int x);
	int pop();
};

void Queue::push(int x) {
	s1.push(x);
}

int Queue::pop() {
	if(s1.empty() && s2.empty()) return -1;
	else{
		if(s2.empty()) {
			while(!s1.empty()) {
				s2.push(s1.top());
				s1.pop();
			}
		}
	}


	int temp = s2.top();
	s2.pop();
	return temp;
}

int main() {
	Queue q;
	q.push(10);
	q.push(30);
	q.push(40);
	q.push(50);
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	cout << q.pop() << endl;
	return 0;	
}
