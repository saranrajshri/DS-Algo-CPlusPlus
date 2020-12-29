//https://www.hackerearth.com/practice/algorithms/searching/binary-search/practice-problems/algorithm/bishu-and-soldiers/

#include<bits/stdc++.h>
using namespace std;

int lowerBound(vector<int>arr, int target) {
	int left = 0;
	int right = arr.size() - 1;

	while(left <= right) {
		int mid = (right - left) + left / 2;

		if(arr[mid] <= target) left = mid + 1;
		else right = mid - 1; 
	}

	return left;
}

void solve() {
	int n;
	cin >> n;
	vector<int>arr(n);
	vector<int> sumArray(n);

	int sum = 0;

	for(int i = 0; i < arr.size(); i++) {
		cin >> arr[i];
		sum += arr[i];
		sumArray[i] = sum;
	}
	int q;
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		int index = lowerBound(arr, x);
		cout << index << " " << sumArray[index - 1] << endl;
	}
}

int main() {
	solve();
	return 0;	
}
