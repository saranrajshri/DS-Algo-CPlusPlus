#include<bits/stdc++.h>
using namespace std;

struct Meeting {
	int start;
	int end;
	int position;
};

bool comparator(Meeting m1, Meeting m2) {
	return m1.end < m2.end;
}

vector<int> solve(vector<pair<int, int>>arr) {
	vector<int> res;
	vector<Meeting> meetings;

	for(int i = 0; i < arr.size(); i++) {
		meetings.push_back(Meeting{arr[i].first, arr[i].second, i + 1});
	}

	sort(meetings.begin(), meetings.end(), comparator);

	int prev = meetings[0].end;
	res.push_back(meetings[0].position);

	for(int i = 1; i < arr.size(); i++) {
		if(meetings[i].start >= prev) {
			res.push_back(meetings[i].position);
			prev = meetings[i].end;
		}
	}

	return res;
}

int main() {
	vector<pair<int, int>> arr = {{1, 2}, {3, 4}, {0, 6}, {5, 7},{8, 9}, {5, 9}};
	vector<int> res = solve(arr);

	for(int x : res) cout << x << " ";
	return 0;	
}

