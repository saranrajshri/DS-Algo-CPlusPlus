#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> solve(vector<int>arr) {
	vector<vector<int>> res;
	sort(arr.begin(), arr.end());

	for(int i = 0; i < arr.size(); i++) {
		int left = i + 1;
		int right = arr.size() - 1;

		while(left < right) {
 			int sum = arr[left] + arr[right] + arr[i];
 			if(sum == 0) {
 				res.push_back(vector<int>{arr[i], arr[left], arr[right]});
 				left++;
 				right--;
 			}else if(sum > 0) {
 				right--;
 			}else {
 				left++;
 			}
		}
	}

	return res;
}

int main() {
	vector<int> arr = {-1,0,1,2,-1,-4};
	vector<vector<int>> res = solve(arr);

	for(auto it : res) {
		for(int x : it) cout << x << " ";
		cout << endl;
	}
	return 0;	
}


