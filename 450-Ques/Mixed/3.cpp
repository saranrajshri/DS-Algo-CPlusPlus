#include<bits/stdc++.h>
using namespace std;

bool isOk(vector<int>arr, int gap, int m) {
	int pos = arr[0];
	int count = 1;

	for(int i = 1; i < arr.size(); i++) {
		if(arr[i] - pos >= gap) {
			count++;
			pos = arr[i];

			if(count == m) return true;
		}
	}
	return false;
}

int helper(vector<int>arr, int m) {
	int left = 0, right = arr[arr.size() - 1];
	int ans = INT_MIN;

	while(left <= right) {
		int mid = (right - left) + left / 2;
		if(isOk(arr, mid, m)) {
			ans = max(ans, mid);
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}

	return ans;
}

void solve() {
	int n, m;
	cin >> n >> m;
	vector<int>arr(n);

	for(int i = 0; i < n; i++) cin >> arr[i];

	sort(arr.begin(), arr.end());
	
	int ans = helper(arr, m);

	cout << ans << endl;
}

int main() {
	int t;
	cin >> t;

	while(t--) {
		solve();
	}
	return 0;	
}
