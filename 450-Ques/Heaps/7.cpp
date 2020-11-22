#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
    
    while(t--) {
	    priority_queue<int, vector<int>> maxHeap1;
	    priority_queue<int, vector<int>> maxHeap2;
	    
	    int m, n;
	    cin >> m >> n;
	    
	    for(int i = 0; i < m; i++) {
	        int x;
	        cin >> x;
	        maxHeap1.push(x);
	    }
	    
	    for(int i = 0; i < n; i++ ){
	        int x;
	        cin >> x;
	        maxHeap2.push(x);
	    }
	    
	    vector<int>res;
	    
	    while(!maxHeap1.empty() && !maxHeap2.empty()) {
	        if(maxHeap1.top() > maxHeap2.top()) {
	            res.push_back(maxHeap1.top());
	            maxHeap1.pop();
	        }else{
	            res.push_back(maxHeap2.top());
	            maxHeap2.pop();
	        }
	    }
	    
	    while(!maxHeap2.empty()) {
	        res.push_back(maxHeap2.top());
	        maxHeap2.pop();
	    }
	    
	    for(int x : res) cout << x << " ";
	   }
	return 0;
}