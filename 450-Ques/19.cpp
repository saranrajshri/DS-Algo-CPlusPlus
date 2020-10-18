#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Three Pointers

	1. if x == y == z, push the element to the result, increment i, j and k pointers;
	2. else if x < y, i++;
	3. else if y < z, j++;
	4. else k++;
	
	Time - O(N);
	Space - O(1);
*/ 

vector<int> commonElement(vector<int>arr1, vector<int>arr2, vector<int>arr3) {
	int i = 0, j = 0, k = 0;
	vector<int> res;

	while(i < arr1.size() && j < arr2.size() && k < arr3.size()) {
		if(arr1[i] == arr2[j] && arr2[j] == arr3[k]) {
			res.push_back(arr1[i]);
			i++;
			j++;
			k++;
		}
		else if(arr1[i] < arr2[j]) i++;
		else if(arr2[j] < arr3[k]) j++;
		else k++;
	}
	return res;
}

int main() {
	vector<int> arr1 = {1, 5, 10, 20, 40, 80};
	vector<int> arr2 = {6, 7, 20, 80, 100}; 
    vector<int> arr3 = {3, 4, 15, 20, 30, 70, 80, 120}; 
	
	vector<int>res = commonElement(arr1, arr2, arr3);
	
	for(int x : res) {
		cout << x << " ";
	}
	return 0;
}