#include<bits/stdc++.h>
using namespace std;

/*
	Time - O(N);
	Space - O(N);
*/ 

int minSwaps(string s) {
	vector<int>pos;

	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '[')
			pos.push_back(i);
	}

	int count = 0;
	int nextPos = 0;

	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '[') {
			count++;
			p++;
		}
		else if(s[i] == ']') count--;

		if(count < 0) {
			sum += pos[p] - i;
			swap(s[pos[p]], s[i]);
			p++;

			count = 1;
		}
	}

	return sum;
}

/*
	Time - O(N);
	Space - O(1);
*/		

int minSwaps(string s) {
	int left = 0;
	int right = 0;
	int swap = 0;

	for(int i = 0; i < s.size(); i++) {
		if(s[i] == '[') {
			left++;

			if(imbalance > 0) {
				swap += imbalance
				imbalance--;
			}
		}
		else if(s[i] == ']') {
			right++;

			imbalance = (right - left);
		}
	}
	return swap;
}


int main() {
    string s = "[]][][";
    cout << minSwaps(s);
	return 0;
}