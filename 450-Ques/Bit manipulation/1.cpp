#include<iostream>
#include<vector>
#include<map>
#include<set>
#include<algorithm>
#include<math.h>
#define int long long
using namespace std;

void solve(vector<int> arr) {
	unsigned int powerSetSize = pow(2, arr.size());

	for(int i = 0; i < powerSetSize; i++) {
		for(int j = 0; j < arr.size(); j++) {
			if(i & (1 << j)) {
				cout << arr[j] << " ";
			}
		}
		cout << endl;
	}
}

int32_t main() {
	vector<int> arr = {1, 2, 3};
	solve(arr);
	return 0;	
}
