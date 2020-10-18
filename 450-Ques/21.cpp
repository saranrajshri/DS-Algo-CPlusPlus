#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Prefix sum, Unordered Set
	Time - O(N);
	Space - O(N);
*/ 

bool subArrayWithZero(vector<int>arr) {
	unordered_set<int>visited;
	int prefixSum = 0;

	for(int i = 0; i < arr.size(); i++) {
		prefixSum += arr[i];

		if(prefixSum == 0 || visited.find(prefixSum) != visited.end()) return true;
		
		visited.insert(prefixSum);
	}

	return false;
}

int main() {
	vector<int>arr = { -3, 2, 3, 1, 6 };
	if(subArrayWithZero(arr)){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}

	return 0;
}