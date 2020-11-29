#include<bits/stdc++.h>
using namespace std;

bool comparator(pair<int,int> pair1, pair<int, int> pair2) {
	double firstVal = (double(pair1.first) / double(pair1.second));
	double secondVal = (double(pair2.first) /  double(pair2.second));

	return firstVal > secondVal;
} 

double solve(vector<pair<int, int>> arr, int capacity) {	
	sort(arr.begin(), arr.end(), comparator);

	int currentWieght = 0;
	double finalAns = 0.0	;

	for(int i = 0; i < arr.size(); i++) {
		if(currentWieght + arr[i].second <= capacity) {
			currentWieght += arr[i].second;
			finalAns += arr[i].first;
		}else{
			int remainingWeight = capacity - currentWieght;
			finalAns += arr[i].first * ((double)remainingWeight / (double)arr[i].second);
			break;
		}
	}

	return finalAns;
}

int main() {
	vector<pair<int, int>> arr = {{60, 10}, {100, 20}, {30, 120}};
	cout << solve(arr, 50);
	return 0;	
}
