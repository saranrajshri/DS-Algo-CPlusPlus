#include<bits/stdc++.h>
using namespace std;

void reverseQueueFirstKElements(queue<int>&q, int k) {
    if(q.empty() || k > q.size()) return;

    stack<int> tempStack;

    for(int i = 0; i < k; i++) {
        tempStack.push(q.front());
        q.pop();
    }

    while(!tempStack.empty()) {
        q.push(tempStack.top());
        tempStack.pop();
    }


    for(int i = 0; i < q.size() - k; i++) {
        q.push(q.front());
        q.pop();
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
  
    int k = 5; 
    reverseQueueFirstKElements(Queue, k); 

    while(!Queue.empty()) {
        cout << Queue.front() << " ";
        Queue.pop();
    }
}

int main() {
    solve();
    return 0;    
}
