#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Stack {
	int top1Index;
	int top2Index;

public:
	int arr[MAX];

	Stack() { 
		top1Index = -1;
		top2Index = (MAX / 2);
	}

	bool push1(int val);
	int pop1();
	int peek1();

	bool push2(int val);
	int pop2();
	int peek2();
};

bool Stack::push1(int val) {
	if(top1Index >= ((MAX / 2) - 1)) return false;
	else{
		top1Index++;
		arr[top1Index] = val;
	}

	return true;
}


int Stack::pop1() {
	int topElement;

	if(top1Index < 0) return -1;
	else{
		topElement = arr[top1Index];
		top1Index--;
	}

	return topElement;
}

int Stack::peek1() {
	int topElement;
	if(top1Index < 0) return -1;
	else{
		topElement = arr[top1Index];
	}

	return topElement;
}

// Stack 2;
bool Stack::push2(int val) {
	if(top2Index >= (MAX - 1)) return false;
	else{
		top2Index++;
		arr[top2Index] = val;
	}

	return true;
}


int Stack::pop2() {
	int topElement;

	if(top2Index < (MAX / 2) - 1) return -1;
	else{
		topElement = arr[top2Index];
		top2Index--;
	}

	return topElement;
}

int Stack::peek2() {
	int topElement;
	if(top2Index < (MAX / 2) - 1) return -1;
	else{
		topElement = arr[top2Index];
	}

	return topElement;
}

int main() {
	Stack s;
	s.push1(10);
	s.push1(20);
	s.push1(30);
	cout << s.pop1() << endl;
	cout << s.peek1() << endl;

	s.push2(10);
	s.push2(20);
	s.push2(30);
	cout << s.pop2() << endl;
	cout << s.peek2() << endl;
	return 0;	
}
