#include<bits/stdc++.h>
using namespace std;

/*
	Approach 1 - Using HashMap
	Time - O(N);
	Space - O(N);
*/		

vector<int> majorityElement(vector<int>arr) {
	unordered_map<int, int>m;
	vector<int>res;

	for(int x : arr) m[x]++;

	for(auto it : m) {
		if(it.second >= arr.size() / 2) res.push_back(it.first);
	}

	return res;
}

/*
	Approach - Boyer Moore Algorithm
	Time - O(N);
	Space - O(1); 		
*/		 	

vector<int> majorityElement(vector<int>arr) {
	int count1 = 0;
	int count2 = 0;
	int candidate1 = -1;
	int candidate2 = -1;
	vector<int>res;

	for(int i = 0; i < arr.size(); i++) {
		if(candidate1 == arr[i]) {
			count1++;
		}else if(candidate2 == arr[i]) {
			count2++;
		}else if(count1 == 0) {
			candidate1 = arr[i];
			count1 = 1;
		}else if(count2 == 0) {
			candidate2 = arr[i];
			count2 = 1;
		}else{
			count1--;
			count2--;
		}
	}

	count1 = 0;
	count2 = 0;

	for(int x : arr) {
		if(x == candidate1) count1++;
		if(x == candidate2) count2++;
	}

	if(count1 >= arr.size() / 2) res.push_back(candidate1);
	if(count2 >= arr.size() / 2) res.push_back(candidate2);


	return res;
}


int main() {
	vector<int> arr = {3, 1, 3, 3, 2}; 
	vector<int>res = majorityElement(arr);
	
	for(int x : res) cout << x << " ";
	return 0;
}