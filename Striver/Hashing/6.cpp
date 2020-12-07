#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr, int k) {
	unordered_map<int, int>m;
	int count = 0;
	int prefixXor = 0;
	
	for(int i = 0; i < arr.size(); i++) {
		prefixXor = prefixXor ^ arr[i];

		if(prefixXor == k) count++;

		if(m.find(k ^ prefixXor) != m.end()) {
			count += m[k ^ prefixXor];
		}

		m[prefixXor]++;
	}

	return count;
}

int main() {
	vector<int>arr = { 4, 2, 2, 6, 4 };
	cout << solve(arr, 6);
	return 0;	
}
