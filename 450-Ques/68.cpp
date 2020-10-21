#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Simple
	Time - O(N);
	Space - O(1);
	 		
 */		

int romanToInteger(string s) {
	unordered_map<char, int> T = { { 'I' , 1 },
                                   { 'V' , 5 },
                                   { 'X' , 10 },
                                   { 'L' , 50 },
                                   { 'C' , 100 },
                                   { 'D' , 500 },
                                   { 'M' , 1000 } };

    int ans = T[s.back()];


    for(int i = s.size() - 2; i >= 0; i--) {
    	if(T[s[i]] < T[s[i + 1]]) ans -= T[s[i]];
    	else ans += T[s[i]];
    }

    return ans;
}

int main() {
	string s = "VIII";
	cout << romanToInteger(s);
	return 0;
}
