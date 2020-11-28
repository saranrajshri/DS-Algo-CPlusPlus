#include<bits/stdc++.h>
using namespace std;

struct Meeting {
	int startTime;
	int endTime;
	int position;
};


bool comparator(Meeting m1, Meeting m2) {
	return (m1.endTime < m2.endTime);
}

vector<int> solve(vector<int> start, vector<int> end) {
	vector<int> res;

	vector<Meeting> arr(start.size());

	for(int i = 0; i < start.size(); i++) {
		arr[i].startTime = start[i];
		arr[i].endTime = end[i];
		arr[i].position = i + 1;
	}

	sort(arr.begin(), arr.end(), comparator);

	int timeLimt = arr[0].endTime;

	res.push_back(arr[0].position);

	for(int i = 0; i < arr.size(); i++) {
		if(arr[i].startTime >= timeLimt) {
			res.push_back(arr[i].position);
			timeLimt = arr[i].endTime;
		}
	}

	return res;
}

int main() {
	vector<int> start = {1,3,0,5,8,5};
	vector<int> end = {2,4,6,7,9,9};

	vector<int> res = solve(start, end);

	for(int x : res) cout << x << " "; 
	return 0;	
}
