#include<bits/stdc++.h>
using namespace std;

/*
	Two pointer approach
	Time - O(n);
	Space - O(1);
*/

vector<int>mergeSortedArrays(vector<int>arr1, vector<int>arr2, int m, int n) {
	int i = m - 1, j = n - 1;
	int k = m + n - 1;


	while(i >= 0 && j >= 0){
		if(arr2[j] > arr1[i]) {
			arr1[k] = arr2[j];
			j--;
			k--;
		}else{
			arr1[k] = arr1[i];
			i--;
			k--;
		}
	}

	while(i >= 0) {
		arr1[k] = arr1[i];
		i--;
		k--;
	}

	while(j >= 0) {
		arr1[k] = arr2[j];
		j--;
		k--;
	}
	return arr1;	
}

int main() {
	int m = 3, n = 3;
	vector<int>arr1 = {1,2,3,0,0,0};
	vector<int>arr2 = {2, 5, 6};

	vector<int>arr = mergeSortedArrays(arr1, arr2, m, n);
	
	for(int x : arr) {
		cout << x << " ";
	}
	return 0;
}