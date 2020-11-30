#include<bits/stdc++.h>
using namespace std;

pair<int, int> solve(vector<int> arr) {
	// repeating number
	// set behaviour
	pair<int, int> res;

	for(int i = 0; i < arr.size(); i++) {
		int index = abs(arr[i]) - 1;
		if(arr[index] > 0) {
			arr[index] = -arr[index];
		}else{
			res.first = abs(arr[i]);
		}
	}

	for(int i = 0; i < arr.size(); i++) {
		if(arr[i] > 0) {
			res.second =  i + 1;
		}
	}

	return res;
}

int main() {
	vector<int> arr =  { 7, 3, 4, 5, 5, 6, 2 };
	pair<int, int> res = solve(arr);

	cout << res.first << " " << res.second << endl;
	return 0;	
}
