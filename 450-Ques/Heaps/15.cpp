#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr) {
	int num1 = 0, num2 = 0;

	sort(arr.begin(), arr.end());

	for(int i = 0; i < arr.size(); i++) {
		if(i & 1) num1 = num1 * 10 + arr[i];
		else num2 = num2 * 10 + arr[i];
	}
		
	return num1 + num2;
}	


int main() {
	vector<int>arr = {5, 3, 0, 7, 4};
	cout << solve(arr);
	return 0;	
}
