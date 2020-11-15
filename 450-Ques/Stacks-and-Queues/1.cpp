#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Stack {
	int topIndex;

public:
	int arr[MAX];

	Stack() { 
		topIndex = -1;
	}

	bool push(int val);
	int pop();
	int peek();
	bool isEmpty();
};

bool Stack::push(int val) {
	if(topIndex >= (MAX - 1)) return false;
	else{
		topIndex++;
		arr[topIndex] = val;
	}

	return true;
}


int Stack::pop() {
	int topElement;

	if(topIndex < 0) return -1;
	else{
		topElement = arr[topIndex];
		topIndex--;
	}

	return topElement;
}

int Stack::peek() {
	int topElement;
	if(topIndex < 0) return -1;
	else{
		topElement = arr[topIndex];
	}

	return topElement;
}

int main() {
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout << s.pop() << endl;
	cout << s.peek() << endl;
	return 0;	
}
