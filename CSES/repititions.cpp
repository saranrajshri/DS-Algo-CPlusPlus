#include<bits/stdc++.h>
using namespace std;

int main() {
	string str;
	cin >> str;

	int currentBest = 1;
	int maxBest = 0;

	for(int i = 1; i < str.size(); i++) {
		if(str[i] != str[i - 1]) {
			maxBest = max(maxBest, currentBest);
			currentBest = 0;
		}
		currentBest++;

	}
	maxBest = max(maxBest, currentBest);
	cout << maxBest << endl;
	return 0;	
}
