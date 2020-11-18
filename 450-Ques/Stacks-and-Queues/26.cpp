#include<bits/stdc++.h>
using namespace std;

queue<int> solve(queue<int>arr) {
	vector<int> res;
	stack<int> tempStack;

	for(int i = 0; i < arr.size() / 2; i++) {
		tempStack.push(arr.front());
	}

	while(!tempStack.empty()) {
		arr.push(tempStack.top());
		tempStack.pop();
	}

	for(int i = 0; i < arr.size() / 2; i++) {
		arr.push(arr.front());
		arr.pop();
	}

	while(!tempStack.empty()) {
		arr.push(tempStack.top());
		tempStack.pop();
		arr.push(arr.front());
		arr.pop();
	}

	return arr;
	
}

int main() {
	queue<int> q; 
    q.push(11); 
    q.push(12); 
    q.push(13); 
    q.push(14); 
    q.push(15); 
    q.push(16); 
    q.push(17); 
    q.push(18); 
    q.push(19); 
    q.push(20); 
   	queue<int> res = solve(q);	
	
	while(!res.empty()) {
		cout << res.front() <<  " ";
		res.pop();
	}
	return 0;	
}
