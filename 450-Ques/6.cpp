#include<bits/stdc++.h>
using namespace std;

// time - O(N)
// Space  - O(1);

void unionAndIntersection(vector<int>arr1, vector<int>arr2) {
	unordered_set<int>s;
	int intersectionCount = 0;

	// Insert the first array into the set
	for(int x : arr1) s.insert(x);

	for(int x : arr2) {
		// If the element is not present the 
		if(s.find(x) == s.end()) {
			s.insert(x);
		}else intersectionCount++;
	}

	cout << s.size() << " " << intersectionCount << endl;

}

int main() {
	vector<int>arr1 = {1, 2, 3, 4, 5};
	vector<int>arr2 = {1, 2, 3};

	unionAndIntersection(arr1, arr2);
	return 0;
}