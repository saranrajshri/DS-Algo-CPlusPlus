#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Simple
	Time - O(N);
	Space - O(1);
*/

string printSequence(string s) {
	vector<string> dict = {"2","22","222", 
                    "3","33","333", 
                    "4","44","444", 
                    "5","55","555", 
                    "6","66","666", 
                    "7","77","777","7777", 
                    "8","88","888", 
                    "9","99","999","9999"
                   }; 
    string res = "";

    for(int i = 0; i < s.size(); i++) {
    	if(s[i] == ' ') res += '0';
    	else{
    		int index = s[i] - 'A';
    		res += dict[index];
    	}
    }

    return res;
}

int main() {
	string s = "GEEKSFORGEEKS";
	cout << printSequence(s);
	return 0;
}
