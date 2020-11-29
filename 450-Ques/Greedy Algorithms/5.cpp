#include<bits/stdc++.h>
using namespace std;

// int solve(vector<pair<int,int>> arr) {

// 	int platFormsNeeded = 1;
// 	int ans = 1;

// 	for(int i = 0; i < arr.size(); i++) {
// 		platFormsNeeded = 1;

// 		for(int  j = i + 1; j < arr.size(); j++) {
// 			if(((arr[i].first >= arr[j].first && arr[i].first <= arr[j].second)) || arr[j].first >= arr[i].first && arr[j].first <= arr[i].second) {
// 				platFormsNeeded++;
// 			}
// 		}

// 		ans = max(ans, platFormsNeeded);
// 	}
	
// 	return ans;
// }

int solve(vector<pair<int, int>> arr) {
	multimap<int, char> m;

	for(int i = 0; i < arr.size(); i++) {
		m.insert(make_pair(arr[i].first, 'a'));
		m.insert(make_pair(arr[i].second, 'd'));
	}

	// for(auto it = m.begin(); it != m.end(); it++) {
		// cout  << it->first << " " << it->second <<  endl;
	// }

	int ans = 0;
	int platFormsNeeded = 0;

	for(auto it : m) {
		if(it.second == 'a') platFormsNeeded++;
		else platFormsNeeded--;
		
		ans = max(ans, platFormsNeeded);
	}

	return ans;
}

int main() {
	vector<pair<int, int>> arr = {{900, 910}, {940,1200}, {950,1120}, {1100,1130}, {1500,1900}, {1800,2000}};
	cout << solve(arr);
	return 0;	
}
