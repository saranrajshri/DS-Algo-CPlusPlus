#include<bits/stdc++.h>
using namespace std;

/*
	Approach

	1. Sort the interval by their first value
	2. Create a resultant vector and push the first interval to it;
	3. Iterate through the given list of intervals;
	4. When the res.back()[1] < interval[i][0], then push the interval to the res. (means that, the interval is not overlapping);
	5. If not, compare the res.back()[1] and the interval[i][1] and assign it to res.back()[1];

	Time - O(n);
	Space - O(1); // Except the res array
*/

vector<vector<int>> mergeIntervals(vector<vector<int>>intervals) {
	vector<vector<int>> res;

	if(intervals.size() == 0) return {};

	res.push_back(intervals[0]);

	for(int i = 0; i < intervals.size(); i++) {
		if(res.back()[1] < intervals[i][0]) res.push_back(intervals[i]);
		else{
			res.back()[1] = max(res.back()[1], intervals[i][1]); 
		}
	}

	return res;
}


int main() {
	vector<vector<int>> arr =  {{1,3},{2,6},{8,10},{15,18}};
	vector<vector<int>> res = mergeIntervals(arr);

	for(auto array : res){
		for(auto x : array) {
			cout << x << " ";  
		}
		cout << endl;
	}
	return 0;
}