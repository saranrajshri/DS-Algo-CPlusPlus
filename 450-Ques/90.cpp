#include<bits/stdc++.h>
using namespace std;

int countSquares(int num) {
	int i = 1;
	int result = 0;

	while(result <= num) {
		i++;
		result = i * i;
	}

	return i - 1;
}

int main() {
	int num = 11;
	cout << countSquares(num);
	return 0;
}