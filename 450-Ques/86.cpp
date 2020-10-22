#include<bits/stdc++.h>
using namespace std;

/*
	KMP Algorithm 
*/		

void computeLPSArray(string text, string pattern, vector<int>&lpsArray) {
	lpsArray[0] = 0;
	int i = 1;
	int len = 0;

	while(i < pattern.size()) {
		if(pattern[i] == pattern[len]) {
			len++;
			lpsArray[i] = len;
			i++;
		}else{
			if(len != 0) {
				len = lpsArray[len - 1];
			}else{
				lpsArray[i] = 0;
				i++;
			}
		}
	}

}

int KMPSearch(string text, string pattern) {
	int M = text.size();
	int N = pattern.size();

	vector<int>lpsArray(N);

	// LPS Array
	computeLPSArray(text, pattern, lpsArray);

	int i = 0;
	int j = 0;

	while(i < M) {
		if(text[i] == pattern[j]) {
			i++;
			j++;
		}

		if(j == N) {
			return i - j;
		}

		if(i < M && text[i] != pattern[j]) {
			if(j != 0) {
				j = lpsArray[j - 1];
			}else{
				i++;
			}
		}
	}

	return -1;
}

int main() {
	string text = "ABABDABACDABABCABAB"; 
    string pattern = "ABABCABAB"; 
	
	cout << KMPSearch(text, pattern);
	return 0;
}