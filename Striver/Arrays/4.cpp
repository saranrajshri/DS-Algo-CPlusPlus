#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>arr1, vector<int> arr2, int m, int n) {
	int i = m - 1;
	int j = n - 1;
	int k = m + n - 1;

	while(i >= 0 && j >= 0) {
		if(arr1[i] > arr2[j]) {
			arr1[k--] = arr1[i--];
		}else{
			arr1[k--] = arr2[j--];
		}
	}

	while(j >= 0) {
		arr1[k--] = arr2[j--];
	}

	return arr1;
}

int main() {
	vector<int>arr1 = {1,2,3,0,0,0};
	vector<int>arr2 = {2,5,6};
	int m = 3;
	int n = 3;

	vector<int> res = solve(arr1, arr2, m, n);
	for(int x : res) cout << x << " ";
	return 0;	
}
