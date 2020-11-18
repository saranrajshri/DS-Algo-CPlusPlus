#include<bits/stdc++.h>
using namespace std;
#define int long long

int32_t main() {
	int n;
	cin >> n;
	int minNumber = INT_MAX;
	int maxNumber = INT_MIN;

	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;

		minNumber = min(minNumber, x);
		maxNumber = max(maxNumber, x);
	}

	cout << maxNumber - minNumber << endl;
	return 0;	
}
