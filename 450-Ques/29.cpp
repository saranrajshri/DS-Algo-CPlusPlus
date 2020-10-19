#include<bits/stdc++.h>
using namespace std;

/*
	Approach 1 - Brute force;
	1. Find the tallest bar in the left side and the right side of the currentElement;
	2. find the min(a, b) - heights[i];
	3. This will give the amount of water stored in the current index;
	4. Add to the result variable;

	Time - o(N ^ 2);
	Space  - O(1);
	
*/ 

int maxArea(vector<int>heights) {
	int maxWaterArea = 0;

	for(int i = 1; i < heights.size() - 1; i++) {
		int left = heights[i];
		for(int j = 0; j < i; j++) {
			left = max(left, heights[j]);
		}

		int right = heights[i];
		for(int j = i + 1; j < heights.size(); j++) {
			right = max(right, heights[j]);
		}

		maxWaterArea = maxWaterArea + (min(left, right) - heights[i]);

	}

	return maxWaterArea;
}

/*
	Approach 2 - Optimal;
	
	Store the tallest bar values in the left and right array;
	This is a three pass solution, But the time complexity can be reduced;

	1. Find the tallest bar in the left side and the right side of the currentElement;
	2. find the min(a, b) - heights[i];
	3. This will give the amount of water stored in the current index;
	4. Add to the result variable;

	Time - o(N);
	Space  - O(N);
	
*/ 

int maxArea(vector<int>heights) {
	int maxWaterArea = 0;
	vector<int> left(heights.size());
	vector<int> right(heights.size());

	left[0] = heights[0];
	for(int i = 1; i < heights.size(); i++) {
		left[i] = max(left[i - 1], heights[i]);
	}

	right[heights.size() - 1] = heights[heights.size() - 1];
	for(int i = heights.size() - 2; i >= 0; i--) {
		right[i] = max(right[i + 1], heights[i]);
	}

	for(int i = 0; i < heights.size(); i++) {
		maxWaterArea += min(left[i], right[i]) - heights[i];
	}

	return maxWaterArea;
}

int main() {
	vector<int>heights = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
	cout << maxArea(heights);

	return 0;
}