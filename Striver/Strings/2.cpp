#include<bits/stdc++.h>
using namespace std;

int  solve(string str) {
   unordered_map<char, int> T = { { 'I' , 1 },
                               { 'V' , 5 },
                               { 'X' , 10 },
                               { 'L' , 50 },
                               { 'C' , 100 },
                               { 'D' , 500 },
                               { 'M' , 1000 } };
    int ans = T[str.back()];

    for(int i = str.size() - 2; i >= 0; i--) {
    	if(T[str[i]] < T[str[i + 1]]) {
    		ans -= T[str[i]];
    	}else{
    		ans += T[str[i]];
    	}
    }

    return ans;
}

int main() {
	string str = "VIII";
	cout << solve(str);
	return 0;	
}
