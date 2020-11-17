#include<bits/stdc++.h>
using namespace std;

vector<int> nextGreaterElement(vector<int>arr) {
	stack<int> s;
	vector<int>res(arr.size());

	for(int i = arr.size() - 1; i >= 0; i--) {
		while(!s.empty() && s.top() <= arr[i]) s.pop();
		if(s.empty()) {
			res[i] = -1;
		}else{
			res[i] = s.top();
		}
		s.push(arr[i]);
	}
	return res;
}

int main() {
	vector<int> arr = {11, 13, 21, 3};
	vector<int> res = nextGreaterElement(arr);
	for(int x : res) cout << x << " "; 
	return 0;	
}
