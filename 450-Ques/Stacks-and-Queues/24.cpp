#include<bits/stdc++.h>
using namespace std;

void reverse(queue<int> &q) {
	stack<int> tempStack;

	while(!q.empty()) {
		tempStack.push(q.front());
		q.pop();
	}

	while(!tempStack.empty()) {
		q.push(tempStack.top());
		tempStack.pop();
	}
}

void solve() {
	queue<int> Queue; 
    Queue.push(10); 
    Queue.push(20); 
    Queue.push(30); 
    Queue.push(40); 
    Queue.push(50); 
    Queue.push(60); 
    Queue.push(70); 
    Queue.push(80); 
    Queue.push(90); 
    Queue.push(100);

    reverse(Queue);

    while(!Queue.empty()) {
    	cout << Queue.front() << " ";
    	Queue.pop();
    }
}

int main() {
	solve();
	return 0;	
}
