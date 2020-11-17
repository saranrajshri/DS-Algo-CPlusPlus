#include<bits/stdc++.h>
using namespace std;

/*
	Implement K Stacks in a single array;
*/

class KStack {
public:
	vector<int> arr;
	vector<int> top;
	vector<int> next;	
	int n, k;
	int nextFreeIndex;
	KStack(int n, int k);
	bool push(int val, int stackNumber);
	int pop(int stackNumber);
	bool isFull(int stackNumber) {
		return (nextFreeIndex == -1);
	}
	bool isEmpty(int stackNumber) {
		return top[stackNumber] == -1;
	}
};

KStack::KStack(int n, int k) {
	for(int i = 0; i < n; i++) {
		arr.push_back(INT_MAX);
		next.push_back(-1);
	}

	for(int i = 0; i < k; i++) {
		top.push_back(-1);
	}


	for(int i = 0; i < n - 1; i++) {
		next[i] = i + 1;
	}
	next[n - 1] = -1;
	
	nextFreeIndex = 0;
}	

bool KStack::push(int val, int stackNumber) {
	if(isFull(stackNumber)) return false;
	else {
		int currentIndex = nextFreeIndex;
		nextFreeIndex = next[currentIndex];

		next[currentIndex] = top[stackNumber];
		top[stackNumber] = currentIndex;

		arr[currentIndex] = val;
	}
	return true;
}

int KStack::pop(int stackNumber) {
	if(isEmpty(stackNumber)) return -1;
	
	int currentIndex = top[stackNumber];
	top[stackNumber] = next[currentIndex];

	next[currentIndex] = nextFreeIndex;
	nextFreeIndex = currentIndex;

	return arr[currentIndex];
}


int main() {
	int k = 3, n = 10; 
    KStack ks(k, n); 
  
    // Let us put some items in stack number 2 
    ks.push(15, 2); 
    ks.push(45, 2); 
  
    // Let us put some items in stack number 1 
    ks.push(17, 1); 
    ks.push(49, 1); 
    ks.push(39, 1); 
  
    // Let us put some items in stack number 0 
    ks.push(11, 0); 
    ks.push(9, 0); 
    ks.push(7, 0); 
  
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl; 
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl; 
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl; 
  
	return 0;	
}
