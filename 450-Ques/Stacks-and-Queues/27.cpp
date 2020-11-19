#include<bits/stdc++.h>
using namespace std;

int solve(vector<int> gas, vector<int> cost) {
	queue<int>q;

	for(int i = 0; i < gas.size(); i++) {
		int temp = gas[i] - cost[i];
		if(temp >= 0) q.push(i);
	}

	while(!q.empty()) {
		int index = q.front();
		int currentIndex = index;
		q.pop();

		bool flag = false;
		int fuel = 0;
		int counter = 0;

		while(1) {
			if(counter == gas.size()) {
				flag = true;
				break;
			}

			fuel += gas[currentIndex] - cost[currentIndex];
			currentIndex = (currentIndex + 1 ) % gas.size();
			if(fuel < 0) break;

			counter++;
		}

		if(flag == true) return currentIndex;
	}
	return -1;
}

int main() {
	vector<int> gas = {1,2,3,4,5};
	vector<int> cost = {3,4,5,1,2};
	cout << solve(gas, cost);
	return 0;	
}
