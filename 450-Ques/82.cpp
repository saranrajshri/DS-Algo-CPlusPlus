#include<bits/stdc++.h>
using namespace std;

/*
	Time - O(n);
	Space - O(CHAR_MAX);
*/ 

int runCustomerSimulation(int noOfComputers, string str) {
	vector<int> visited(26, 0); 
	int res = 0;
	int occupied = 0;

	for(int i = 0; i < str.size(); i++) {
		int index = str[i] - 'a';
		if(visited[index] == 0) {
			visited[index] = 1;

			if(occupied < noOfComputers) {
				occupied++;
				visited[index] = 2;
			}
			else{
				res++;
			}
		}
		// If its the second occurence
		else{
			if(visited[index] == 2) {
				occupied--;
			}
			visited[index] = 0;
		}
	}

	return res;
}

int main() {
	cout << runCustomerSimulation(2, "ABBAJJKZKZ") << endl; 
    cout << runCustomerSimulation(3, "GACCBDDBAGEE") << endl; 
    cout << runCustomerSimulation(3, "GACCBGDDBAEE") << endl; 
    cout << runCustomerSimulation(1, "ABCBCA") << endl; 
    cout << runCustomerSimulation(1, "ABCBCADEED") << endl; 
	return 0;
}
