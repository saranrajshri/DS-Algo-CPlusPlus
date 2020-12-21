#include<bits/stdc++.h>
using namespace std;

class Stack {
	stack<int> s;
	int minimumElement;

public:
	void push(int val);
	void pop();
	int getMin();
};

void Stack::push(int val) {
	if(s.empty()) {
		minimumElement = val;
		s.push(val);
	}

	if(val < minimumElement) {
		s.push(2 * val - minimumElement);
	}else{
		s.push(val);
	}
}


void Stack::pop() {
	if(s.empty()) return;

	int topAns = s.top();
	s.pop();

	if(topAns < minimumElement) {
		minimumElement = 2 * minimumElement - topAns;
	}
}

int Stack::getMin() {
	if(s.empty()) return -1;
	return minimumElement;
}

int main() {
	Stack s; 
    s.push(3); 
    s.push(5); 
    cout << s.getMin() << endl; 
    s.push(2); 
    s.push(1); 
    cout << s.getMin() << endl;
    s.pop(); 
    cout << s.getMin(); 
    s.pop(); 
	return 0;	
}
