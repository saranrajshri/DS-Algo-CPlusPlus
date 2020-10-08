#include<bits/stdc++.h>
using namespace std;

long long int atoi(string str) {
	long long int  result = 0;
	int indicator = 1;

	int i = str.find_first_not_of(' ');

	// If the string is empty, i value will be -1 
	if(i == 1) return 0;

	if(str[i] == '-' || str[i] == '+') {
		indicator = (str[i++] == '-') ? -1 : 1;
	}

	while(isdigit(str[i])) {
		result = result * 10 + (str[i++] - '0');
		if(result * indicator >= INT_MAX) return INT_MAX;
		if(result * indicator <= INT_MIN) return INT_MIN;
  	}

  	return result;
}

int main() {
	string str = "55";

	cout << atoi(str);

	return 0;
}