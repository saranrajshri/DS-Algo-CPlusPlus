#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arr, int k)  {
	priority_queue<int, vector<int>, greater<int>> q;
	vector<int> prefixSumArr(arr.size() + 1);
	prefixSumArr[0] = 0;
	prefixSumArr[1] = arr[1];

	for(int i = 2; i <= arr.size(); i++) {
		prefixSumArr[i] = prefixSumArr[i - 1] + arr[i - 1];
	}

	for(int i = 1; i <= arr.size(); i++) {
		for(int j = i; j <= arr.size(); j++) {
			int x = prefixSumArr[j] - prefixSumArr[i - 1];

			if(q.size() < k) q.push(x);
			else{
				if(q.top() < x) {
					q.pop();
					q.push(x);
				}
			}
		}
	}

	return q.top();
}

int main() {
	vector<int>arr = {10, -10, 20, -40};
	int k = 6;
	cout << solve(arr, k);
	return 0;	
}
