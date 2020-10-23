#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Count Array;
	Time - O(n);
	Space - O(1);
*/ 

vector<int> missingAndRepeatingNumber(vector<int>arr) {
	vector<int>visited(arr.size(), 0);
	vector<int>res(2,0);

	for(int i = 0; i < arr.size(); i++) {
		if(visited[arr[i]] == 0) {
			visited[arr[i]] = 1;
		}else if(visited[arr[i]] == 1){
			// Repeating Element
			res[0] = arr[i];
		}
	}

	for(int i = 0; i < res.size(); i++) {
		if(res[i] == 0) {
			res[1] = i;
			break;
		}
	}

	return res;
}

/*
	Approach - Use indexes to mark as visited
	Time - O(N);
	Space - O(1);
*/ 

vector<int> missingAndRepeatingNumber(vector<int>arr) {
	vector<int>res(2, 0);

	for(int i = 0; i < arr.size(); i++) {
		int index = abs(arr[i] - 1);
		if(arr[index] > 0) {
			arr[index] = -1 * arr[index];
		}else{
			res[0] = abs(arr[i]);
		}
	}

	for(int i = 0; i < arr.size(); i++) {
		if(arr[i] > 0) {
			res[1] = i + 1;
		}
	}
	
	return res;
}

int main() {
	vector<int>arr = {7, 3, 4, 5, 5, 6, 2};
	vector<int>res = missingAndRepeatingNumber(arr);
	cout << res[0] << " " << res[1];
	return 0;
}