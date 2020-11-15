#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

class Queue {
	int left;
	int right;

public:
	int arr[MAX];

	Queue() {
		left = -1;
		right = -1;
	}

	bool push(int val);
	int pop();
	int front();
	int back();
};

bool Queue::push(int val) {
	if(right >= (MAX - 1)) return false;
	else if(right == -1 && left == -1) {
		left = 0;
		right++;
		arr[right] = val;
	}
	else{
		right++;
		arr[right] = val;
	}

	return true;
}

int Queue::pop() {
	int temp;
	if(left < 0) return false;
	else{
		temp = arr[left];
		left++;
	}

	return temp;
}

int Queue::front() {
	if(left < 0) return -1;
	return arr[left];
}

int Queue::back() {
	if(right >= (MAX - 1)) return -1;
	return arr[right];
}

int main() {
	Queue q;
	q.push(10);
	q.push(20);
	q.push(30);
	cout << q.front() << endl;
	cout << q.back() << endl;
	cout << q.pop() << endl;
	return 0;	
}
