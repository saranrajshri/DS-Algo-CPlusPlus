#include<bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;
	int count = 0;
	for(char x : str) {
		if(x == '4' || x == '7') {
			count++;
		}
	}	

	if(count == 4 || count == 7) {
		cout << "YES" << endl;	
	}else{
		cout << "NO" << endl;
	}
	return 0;	
}
