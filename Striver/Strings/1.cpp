#include<bits/stdc++.h>
using namespace std;

vector<int> getIndex(string str, int left, int right) {
	while(left >= 0 && right < str.size()) {
		if(str[left] != str[right]) break;
		else{
			left--;
			right++;
		}
	}

	return vector<int>{left + 1, right};
}

string solve(string str) {
	vector<int> longest = {0, 1};

	for(int i = 1; i < str.size(); i++) {
		vector<int> odd = getIndex(str, i - 1, i + 1);
		vector<int> even = getIndex(str, i - 1, i);

		vector<int> currentLongest = odd[1] - odd[0] > even[1] - even[0] ? odd : even;
		longest = longest[1] - longest[0] > currentLongest[1] - currentLongest[0] ? longest : currentLongest;
	}

	return str.substr(longest[0], longest[1] - longest[0]);
}

int main() {
	string str = "babad";
	cout << solve(str);
	return 0;	
}

