#include<bits/stdc++.h>
using namespace std;


/*
	https://www.geeksforgeeks.org/factorial-large-number/
	Use a array to store the values;

	Time - O(N ^ 2);
	Space - O(N) where N is the length of the resultant array
*/ 

int multiply(int x, vector<int>&res, int &resSize) {
	int carry = 0;

	for(int i = 0; i < resSize; i++) {
		int prod = res[i] * x + carry;
		res[i] = prod % 10;
		carry = prod / 10;
	}

	while(carry) {
		res[resSize] = carry % 10;
		carry /= 10;
		resSize++;
	}

	return resSize;
}

void factorial(int num) {
	vector<int>res(500);
	res[0] = 1;
	int resSize = 1;

	for(int i = 2; i <= num; i++) {
		resSize = multiply(i, res, resSize);
	}

	for(int i = resSize - 1; i >=0; i--) {
		cout << res[i];
	}
}

int main() {
	factorial(100);
	return 0;
}