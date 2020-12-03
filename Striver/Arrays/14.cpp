#include<bits/stdc++.h>
using namespace std;

vector<int> solve(vector<int>arr) {
	int candidate1 = -1;
	int candidate2 = -1;
	int count1 = 0;
	int count2 = 0;

	for(int i = 0; i < arr.size(); i++) {
		if(candidate1 == arr[i])  count1++;
		else if(candidate2 == arr[i]) count2++;
		else if(count1 == 0) {
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

	vector<int>res;	
	count1 = 0;
	count2 = 0;

	for(int x : arr) {
		if(x == candidate1) count1++;
		else if(x == candidate2) count2++;
	}

	if(count1 > arr.size() / 3) res.push_back(candidate1);
	if(count2 > arr.size() / 3) res.push_back(candidate2);

	return res;
}


int main() {
	vector<int>arr = {3, 2, 3};
	vector<int>res = solve(arr);

	for(int x : res) cout << x << " ";
	return 0;	
}
