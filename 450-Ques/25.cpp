#include<bits/stdc++.h>
using namespace std;


/*
	https://www.geeksforgeeks.org/given-an-array-of-of-size-n-finds-all-the-elements-that-appear-more-than-nk-times/

	Approach 1 - Hashmap
	Time - O(N);
	Space - O(N);
*/ 

vector<int>countElements(vector<int>arr, int k){
	vector<int>res;
	unordered_map<int, int>m;
	
	for(int x : arr) m[x]++;

	for(auto it : m){
		if(it.second >= arr.size() / k) res.push_back(it.first);
	}

	return res;
}


/*
	Constant Space Version
	https://leetcode.com/problems/majority-element-ii/
	
	Approach 2 - Boyer Moore Algorithm
	Time - O(N);
	Space - O(1);
*/ 

vector<int>countElements(vector<int>arr, int k){
	vector<int>res;
	int candidate1 = -1, candidate2 = -1, count1 = 0, count2 = 0;	

	for(int i = 0; i < arr.size(); i++) {
		if(candidate1 == arr[i]) count1++;
		if(candidate2 == arr[i]) count2++;
		else if(count1 == 0) {
			candidate1 = arr[i];
			count1 = 1;
		}
		else if(count2 == 0) {
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
 		else if(x == candidate2) count2++;
 	} 

 	if(count1 > arr.size() / k) res.push_back(candidate1);
 	if(count2 > arr.size() / k) res.push_back(candidate2);

 	return res;
}



int main() {
	vector<int>arr = {4, 5, 6, 7, 8, 4, 4};
	int k = 3;

	vector<int>res = countElements(arr, k);
	for(int x : res) cout << x << " "; 
	return 0;
}