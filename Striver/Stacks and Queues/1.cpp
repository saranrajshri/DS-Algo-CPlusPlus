#include<bits/stdc++.h>
using namespace std;

class Stack {
	int topIndex;
public:
	vector<int> arr(100);
	Stack();
	bool push(int val);
	int pop();
	int peek();
};

Stack::Stack() {
	topIndex = -1;	
}

bool Stack::push(int val) {
	if(topIndex >= 100 - 1) {
		return false;
	}else{
		arr[++topIndex] = val;
	}

	return true;
}

int Stack::pop() {
	if(topIndex <= -1) return false;
	return arr[topIndex--];
}

int Stack::peek() {
	if(topIndex <= -1) return INT_MIN;
	return arr[topIndex];
}

int main() {
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.pop() << " " << s.pop() << endl; 

	return 0;	
}
