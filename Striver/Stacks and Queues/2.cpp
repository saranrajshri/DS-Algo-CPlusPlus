#include<bits/stdc++.h>
using namespace std;

class Stack {
	queue<int> q1, q2;

public:
	void push(int val);
	int pop();
	int peek();
};

void Stack::push(int val) {
	q2.push(val);

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
	int ans = q1.front();
	q1.pop();
	return ans;
}

int Stack::peek() {
	if(q1.empty()) return -1;
	return q1.front();
}

int main() {
 Stack s; 
    s.push(1); 
    s.push(2); 
    s.push(3); 
  
    cout << s.peek() << endl; 
    s.pop(); 
    cout << s.peek() << endl; 
    s.pop(); 
    cout << s.peek() << endl; 
	return 0;	
}
