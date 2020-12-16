#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--) {
	    int n, k;
	    cin >> n >> k;
	    vector<int>arr(n);
	    
	    for(int i = 0; i < n; i++) cin >> arr[i];
	    
	    sort(arr.begin(), arr.end());
	    
	   	int i = 0;

	   	while(k > 0) {
	   		if(arr[i] == 0) {
	   			k = 0;
	   		}else{
	   			arr[i] = (-1) * arr[i];
	   			k--;
	   		}
	   		i++;
	   	}
	    
		int sum = 0;
		for(int x : arr) sum += x;

		cout << sum << endl;	    
	}
 	return 0;
}