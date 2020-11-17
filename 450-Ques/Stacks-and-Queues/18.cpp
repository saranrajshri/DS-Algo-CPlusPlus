#include<bits/stdc++.h>
using namespace std;

bool isRedundant(string str) {
	int operators = 0;
	int brackets = 0;

	for(int i = 0; i < str.size(); i++) {
		if(str[i] == '(' && str[i + 2] == ')') return true;
		if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') operators++; 
		if(str[i] == '(') brackets++;
	}

	if(brackets > operators) return true;

	return false;
}

int main() {
	string str = "(((a+b) + c) + d)";
	if(isRedundant(str)) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	return 0;	
}
