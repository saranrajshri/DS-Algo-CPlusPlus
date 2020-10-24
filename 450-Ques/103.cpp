#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Sort with Comparator
	Time - O(N log N);
	Space - O(1);
*/ 
int countBits(int num) {
	int count = 0;
	while(num) {
		count += num & 1;
		num >>= 1;
	}

	return count;
}

vector<int> sortBySetBits(vector<int>arr) {
	auto comp = [](const int &a, const int &b) {
		int countA = countBits(a);
		int countB = countBits(b);

		if(countA <= countB) return false;

		return true;
	};

	stable_sort(arr.begin(), arr.end(), comp);

	return arr;
}

int main() {
	vector<int> arr =  {1, 2, 3, 4, 5, 6};
	vector<int>res = sortBySetBits(arr);
	for(int x : res) cout << x << " ";
	return 0;
}