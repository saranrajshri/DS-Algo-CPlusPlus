#include<bits/stdc++.h>
using namespace std;

struct Info {
	char charecter;
	int freq;
	bool operator<(const Info &k) const { 
        return freq < k.freq; 
    } 
};

string solve(string str) {
	unordered_map<char, int> m;
	for(char x : str) m[x]++;
	
	priority_queue<Info> q;
	
	for(auto it : m) {
		q.push(Info{it.first, it.second});
	}

	string res = "";
	
	Info prev{'#', -1};

	while(!q.empty()) {
		Info temp = q.top();
		q.pop();
		res += temp.charecter;
		if(temp.freq > 0) q.push(temp);	

		(temp.freq)--;
		prev = temp;
	}

	return res;
}

int main() {
	string str = "aab";
	cout << solve(str);
	return 0;
}
