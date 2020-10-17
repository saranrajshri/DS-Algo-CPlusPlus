#include<bits/stdc++.h>
using namespace std;

void rotate(vector<int>&arr) {
	int lastElement = arr[arr.size() - 1];
	for(int i = arr.size() - 1; i > 0; i--) {
		arr[i] = arr[i - 1];
		arr[0] = lastElement;
	}
}

int main() {
	vector<int>arr = {1, 2, 3, 4};
	rotate(arr);

	for(int x : arr) {
		cout << x << " ";
	}
	return 0;
}