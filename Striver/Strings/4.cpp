#include<bits/stdc++.h>
using namespace std;

int solve(string str) {
	long long int result = 0;
	int indicator = 1;

	int i = str.find_first_not_of(' ');

	if(str[i] == '+' || str[i] == '-') {
		indicator = (str[i++] == '-') ? -1 : 1;
	}

	while(isdigit(str[i])) {
		result = result * 10 + (str[i++] - '0');
		if(result * indicator >= INT_MAX) return INT_MAX;
		if(result * indicator <= INT_MIN) return INT_MIN;
	}

	return result * indicator;
}

int main() {
	string str = "-4000";
	cout << solve(str);
	return 0;	
}
