#include<bits/stdc++.h>
using namespace std;

int solve(string version1, string version2) {
	for(int i = 0, j = 0; (i < version1.size() || j < version2.size());) {
		int valueNumOne = 0, valueNumTwo = 0;

		while(i < version1.size() && version1[i] != '.') {
			valueNumOne = valueNumOne * 10 + (version1[i] - '0');
			i++;
		}

		while(j < version2.size() && version2[j] != '.') {
			valueNumTwo = valueNumTwo * 10 + (version2[j] - '0');
			j++;
		}

		if(valueNumOne > valueNumTwo) return 2;
		else if(valueNumOne < valueNumTwo) return 1;

		valueNumOne = valueNumTwo = 0;
		i++;
		j++;
 	}

 	return -1;	
}

int main() {
	string version1 = "1.0.3"; 
    string version2 = "1.0.7"; 

    cout << solve(version1, version2);
	return 0;	
}
