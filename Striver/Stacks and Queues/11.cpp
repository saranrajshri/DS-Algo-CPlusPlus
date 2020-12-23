#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr) {
	int maxArea = INT_MIN;
	int n = arr.size();

	vector<int> left(n);
	vector<int> right(n);

	stack<int> s;

	for(int i = 0; i < n; i++) {
		if(s.empty()) {
			left[i] = 0;
			s.push(i);
		}else{
			while(!s.empty() && arr[s.top()] >= arr[i]) {
				s.pop();
			}

			left[i] = s.empty() ? 0 : s.top() + 1;
			s.push(i);
		}
	}

	while(!s.empty()) s.pop();

	for(int i = n - 1; i >= 0; i--) {
		if(s.empty()) {
			right[i] = n - 1;
			s.push(n - 1);
		}else{
			while(!s.empty() && arr[s.top()] >= arr[i]) {
				s.pop();
			}

			right[i] = s.empty() ? n - 1 : s.top() - 1;
			s.push(i);
		}
	}

	for(int i = 0; i < n; i++) {
		maxArea = max(maxArea, (right[i] - left[i] + 1) * arr[i]);
	}

	return maxArea;
}

int main() {
	vector<int>arr = {2,1,5,6,2,3};
	cout << solve(arr);
	return 0;	
}
