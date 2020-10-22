#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Sliding Window
	Time - O(N);
	Space - O(N);
*/ 


string smallestDistinctWindow(string str) {	
	unordered_set<char>s;
	unordered_map<char, int> m;

	int distinctCount = 0;
	for(char c : str) {
		if(s.find(c) == s.end()) {
			distinctCount++;
			s.insert(c);
		}
	}

	int left = 0;
	int currentDistinctCount = 0;
	int minLength = INT_MAX;
	int startIndex = -1;

	for(int right = 0; right < str.size(); right++) {
		m[str[right]]++;

		// Means, it is a distinct char
		if(m[str[right]] == 1) {
			currentDistinctCount++;
		}

		if(currentDistinctCount == distinctCount) {
			while(m[str[left]] > 1) {
				if(m[str[left]] > 1) {
					m[str[left]]--;
				}
				left++;
			}

			if(minLength > right - left + 1) {
				minLength = right - left + 1;
				startIndex = left;
			}
		}
	}

	return str.substr(startIndex, minLength);
}




int main() {
	string s = "aabcbcdbca";
	cout << smallestDistinctWindow(s);
	return 0;
}