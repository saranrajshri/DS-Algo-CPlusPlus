#include<bits/stdc++.h>
using namespace std;

void swap(string &str, int left, int right) {
	char temp = str[left];
	str[left] = str[right];
	str[right] = temp;
}

void helper(string str, int left, int right) {
	if(left == right) {
		cout << str << endl;
	}
	else{
		for(int i = left; i <= right; i++) {
			swap(str[left], str[i]);

			helper(str, left + 1, right);

			swap(str[left], str[i]);
		}
	}
}


int main() {
	string str = "ABC";
	helper(str, 0, str.size() - 1);
	return 0;
}