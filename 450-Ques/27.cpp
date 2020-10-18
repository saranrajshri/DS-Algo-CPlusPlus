#include<bits/stdc++.h>
using namespace std;

/*
	Approach 1 - Sorting
	Time - O(N log N);
	Space - O(1);
*/ 
bool isSubArray(vector<int>arr1, vector<int>arr2) {
	int i = 0;
	int j = 0;
	int count = 0;

	while(i < arr1.size() &&  j < arr2.size()) {
		if(arr1[i] == arr2[j]) {
			i++;
			j++;
			count++;
		}else{
			i++;
		}
	}

	return count == arr2.size();
}

/*
	Approach 2 - Hashing
	Two pass approach

	Time - O(N);
	Space - O(N) where N if is the number of elements in arr1;
*/ 

bool isSubArray(vector<int>arr1, vector<int>arr2) {
	unordered_map<int, int>m;
	int count = 0;

	for(int x : arr1) m[x]++;

	for(int x : arr2) {
		if(m.find(x) != m.end()) count++; 
	}

	return count == arr2.size();
}

int main() {
	vector<int>arr1 = {11, 1, 13, 21, 3, 7};
	vector<int>arr2 = {11, 3, 7, 1};

	sort(arr1.begin(), arr1.end());
	sort(arr2.begin(), arr2.end());

	if(isSubArray(arr1, arr2)) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;
}