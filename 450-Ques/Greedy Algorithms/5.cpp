#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> pair1, pair<int, int> pair2) {
	return pair1.second < pair2.second;
} 

int solve(vector<pair<int,int>> arr) {
	int count = 0;

	sort(arr.begin(), arr.end(), comparator);

	int prev = arr[0].second;

	for(int i = 1; i < arr.size(); i++) {
		if(prev >= arr[i].first) {
			count++;
			prev = arr[i].second;
		}
	}

	return count;
}

int main() {
	vector<pair<int, int>> arr = {{900, 910}, {940,1200}, {950,1120}, {1100,1130}, {1500,1900}, {1800,2000}};
	cout << solve(arr);
	return 0;	
}
