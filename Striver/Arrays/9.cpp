#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>arr) {
	int k, l;

	for(k = arr.size() - 2; k >= 0; k--) {
		if(arr[k] < arr[k + 1]) break;
	}

	if(k < 0) {
		reverse(arr.begin(), arr.end());
	}
	else{
		for(l = arr.size() - 1; l > k; l--) {
			if(arr[l] > arr[k]) break;
		}

		swap(arr[l], arr[k]);

		reverse(arr.begin() +  k + 1, arr.end());
	}	

	return arr;
}

int main() {
	vector<int>arr = {1, 2, 3};
	vector<int> res = solve(arr);

	for(int x : res) cout << x << " ";
	return 0;	
}
