#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>arr, int k) {
	deque<int>maxQ(k);
	deque<int>minQ(k);
	vector<int>res;
	int sum = 0;

	for(int i = 0; i < k; i++) {
		while(!maxQ.empty() && arr[maxQ.back()] <= arr[i]) maxQ.pop_back();
		while(!minQ.empty() && arr[minQ.back()] >= arr[i]) minQ.pop_back();

		maxQ.push_back(i);
		minQ.push_back(i);
	}

	for(int i = k; i < arr.size(); i++) {
		sum += arr[maxQ.front()] + arr[minQ.front()];

		while(!maxQ.empty() && maxQ.front() <= i - k) maxQ.pop_front();
		while(!minQ.empty() && minQ.front() <= i - k) minQ.pop_front();

		while(!maxQ.empty() && arr[maxQ.back()] <= arr[i]) maxQ.pop_back();
		while(!minQ.empty() && arr[minQ.back()] >= arr[i]) minQ.pop_back();

		maxQ.push_back(i);
		minQ.push_back(i);
	}

	sum += arr[maxQ.front()] + arr[minQ.front()];

	return sum;
}

int main() {
	vector<int> arr = {2, 5, -1, 7, -3, -1, -2};
	int k = 3;
	cout << solve(arr, k);

	return 0;	
}
