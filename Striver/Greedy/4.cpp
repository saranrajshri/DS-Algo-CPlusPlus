#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int, int> p1, pair<int, int>p2) {
	double ans1 = p1.first / p1.second;
	double ans2 = p2.first / p2.second;

	return ans1 > ans2;
}

double solve(vector<pair<int, int>> arr, int capacity) {
	sort(arr.begin(), arr.end(), comparator);
	double currentWeight = 0.0;
	double currentProfit = 0.0;

	for(int i = 0; i < arr.size(); i++) {
		if(currentWeight + arr[i].second <= capacity) {
			currentWeight += arr[i].second;
			currentProfit += arr[i].first;
		}else{
			int remain = capacity - currentWeight;
			currentProfit += arr[i].first * (double((remain / arr[i].second)));
			break;
		}
	}

	return currentProfit;
}

int main() {
	vector<pair<int, int>> arr = { { 60, 10 }, { 100, 20 }, { 120, 30 } }; 
	cout << solve(arr, 50);
	return 0;	
}
