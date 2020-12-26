#include<bits/stdc++.h>
using namespace std;

int main() {
	double n;
	cin >> n;
	double sum = 0.0;

	for(int i = 0; i < n; i++) {
		int x;
		cin >> x;
		sum += x;
	}
	cout << fixed << setprecision(12) << sum / n << endl;
	return 0;	
}
