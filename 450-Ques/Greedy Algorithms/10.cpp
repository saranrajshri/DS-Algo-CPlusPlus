#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr) {
	int countZeros = 0;
	int negativeCount = 0;
	int product = 1;
	int maxNegative = INT_MIN;

	for(int i = 0; i < arr.size(); i++) {
		if(arr[i] == 0) countZeros++;

		else if(arr[i] < 0) {
			negativeCount++;
			maxNegative = max(maxNegative, arr[i]);
		}
		
		product *= arr[i];
	}

	if(countZeros == arr.size()) return 0;

	if(negativeCount & 1) {
		if(negativeCount == 1 && countZeros > 0 && countZeros + negativeCount == arr.size()) return 0;

		product = product / maxNegative;
	}

	return product;
}

int main() {
	vector<int>arr =  {  -1, -1, -2, 4, 3  };
	cout << solve(arr);
	return 0;	
}
