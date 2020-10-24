#include<bits/stdc++.h>
using namespace std;



int main() {
	int t;
	cin >> t;

	while(t--) {
		int n, q;
		cin >> n >> q;
		vector<int>arr;

		while(n--) {
			int a, b;
			cin >> a >> b;
			for(int i = a; i <= b; i++) arr.push_back(i);		
		}

		sort(arr.begin(), arr.end());
		
		while(q--) {
			int x;
			cin >> x;

			if(x - 1 < arr.size()) {
				cout << arr[x - 1] << endl;
			}else{
				cout << -1 << endl;
			}
		}
	}
	return 0;
}
