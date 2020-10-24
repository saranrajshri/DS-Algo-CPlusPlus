#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Graph Method
	Time - O(N log N);
	Space- O(N);
*/ 

int minSwaps(vector<int>arr) {
	pair<int, int>currentPair;
	vector<pair<int, int>> correctOrder;

	for(int i = 0; i < arr.size(); i++) {
		currentPair.first = arr[i];
		currentPair.second =  i;
		correctOrder.push_back(currentPair);
	}

	// Sort the correctOrder array by its first value;

	sort(correctOrder.begin(), correctOrder.end());
	vector<bool>visited(arr.size(), false);

	int cycles = 0;

	for(int i = 0; i < arr.size(); i++) {
		// If the element is already swapped or if the element is in its correct position
		if(visited[i] || correctOrder[i].second == i) continue; 
	
		int j = i;
		int currentCycleSize = 0;

		while(!visited[j]) {
			visited[j] = true;
			j = correctOrder[i].second;

			currentCycleSize++;
		}

		cycles += (currentCycleSize - 1);
	}

	return cycles;
}

int main() {
	vector<int> arr = {1, 5, 4, 3, 2};
	cout << minSwaps(arr);
	return 0;
}