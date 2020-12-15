#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> arrival, vector<int> departure) {
	multimap<int, char> m;

	for(int i = 0; i < arrival.size(); i++) {
		m.insert(make_pair(arrival[i], 'a'));
		m.insert(make_pair(departure[i], 'd'));
	}

	int ans = INT_MIN;
	int count = 0;

	for(auto it : m) {
		if(it.second == 'a') count++;
		else {
			count--;
		}
		ans = max(ans, count);
	}

	return ans;
}

int main() {
	vector<int>arrival = { 900, 940, 950, 1100, 1500, 1800 };
	vector<int> departure = { 910, 1200, 1120, 1130, 1900, 2000 };
	cout << solve(arrival, departure);
	return 0;	
}

