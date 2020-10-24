#include<bits/stdc++.h>
using namespace std;


int main() {
	int n;
	cin >> n;
	vector<int>arr(n);
	
	for(int i = 0; i < n; i++) cin >> arr[i];

	int q;
	cin >> q;

	while(q--) {
		int temp;
		cin >> temp;
		int count = 0;
		int sum = 0;

		for(int i = 0; i < arr.size(); i++) {
			if(arr[i] <= temp) {
				sum += arr[i];
				count++;
			}
		}

		cout << count << " " << sum << endl;
	}
	return 0;
}
