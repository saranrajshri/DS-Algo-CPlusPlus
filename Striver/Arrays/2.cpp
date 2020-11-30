#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int> arr) {
	int low = 0;
	int mid = 0;
	int high = arr.size() - 1;

	while(mid <= high) {
		switch(arr[mid]) {
			case 0:
				swap(arr[low], arr[mid]);
				low++;
				mid++;
				break;
			case 1:
				mid++;
				break;
			case 2:
				swap(arr[high], arr[mid]);
				high--;
				break;
		}
	}

	return arr;
}

int main() {
	vector<int>arr = {0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1};
	vector<int>res = solve(arr);

	for(int x : res) cout << x << " ";
	return 0;	
}
