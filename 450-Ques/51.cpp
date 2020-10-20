#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Concatenation

	Create a new string and append str1.str1;
	If Str2 is a substring of new String, then it is a rotation;

	Time - O(N), KMP Algorithm
	Space - O(N);
*/ 

bool isRotation(string str1, string str2) {
	string temp = str1 + str1;
	size_t found = str1.find(str2);
	if(found != string::npos) {
		return true;
	} else return false;
}	

int main() {
	string str1 = "ABACD";
    string str2 = "CDABA";

    if(isRotation(str1, str2)) {
    	cout << "Yes" << endl;
    }else{
    	cout << "No" << endl;
    }

	return 0;
}