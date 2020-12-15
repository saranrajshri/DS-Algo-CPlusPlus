#include<bits/stdc++.h>
using namespace std;

vector<int> solve(int amount, vector<int> denominations) {
	vector<int> res;

	sort(denominations.begin(), denominations.end(), greater<int>());

	for(int i = 0; i < denominations.size(); i++) {
		while(amount >= denominations[i]) {
			amount -= denominations[i];
			res.push_back(denominations[i]);
		}
	}
	
	return res;
}

int main() {
	vector<int> denominations =  { 1, 2, 5, 10, 20, 50, 100, 500, 1000 }; 
	int amount = 93;
	vector<int> res = solve(amount, denominations);

	for(int x : res) cout << x << " ";
	return 0;	
}
