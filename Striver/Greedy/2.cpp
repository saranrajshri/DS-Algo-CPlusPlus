#include<bits/stdc++.h>
using namespace std;

struct Activity {
	int start;
	int end;
	int position;
};

bool comparator(Activity a1, Activity a2) {
	return a1.end < a2.end;
}

vector<int> solve(vector<pair<int, int>> arr) {
	vector<Activity> activities;
	vector<int> res;
		
	for(int i = 0; i < arr.size(); i++) {
		activities.push_back(Activity{arr[i].first, arr[i].second, i});
	}

	sort(activities.begin(), activities.end(), comparator);

	int prev = activities[0].end;
	res.push_back(activities[0].position);

	for(int i = 1; i < arr.size(); i++) {
		if(activities[i].start >= prev) {
			res.push_back(activities[i].position);
			prev = activities[i].end;
		}
	}

	return res;
}

int main() {
	vector<pair<int, int>> arr = {{1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {5, 9}};
	vector<int>res = solve(arr);

	for(int x : res) cout << x << " ";
	return 0;	
}
