#include<bits/stdc++.h>
using namespace std;

class Queue {
	stack<int> s1, s2;
public:
	void enqueue(int val);
	int dequeue();
};

void Queue::enqueue(int val) {
	while(!s1.empty()) {
		s2.push(s1.top());
		s1.pop();
	}

	s1.push(val);

	while(!s2.empty()) {
		s1.push(s2.top());
		s2.pop();
	}
}

int Queue::dequeue() {
	if(s1.empty()) {
		return -1;
	}
	int ans = s1.top();
	s1.pop();

	return ans;
}

int main() {
	return 0;	
}
