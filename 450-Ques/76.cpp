#include<bits/stdc++.h>
using namespace std;

/*
	Approach - Using Max Heap;

	Calculate the freq of all the charecters and push it to the max heap
	pop the front element from the heap and add the char to the res;
	decrement the freq;
	if the freq of the previous element is > 0, then push it again to the heap;


	Time - O(N);
	Space - O(N);
*/ 

struct Key{
	char letter;
	int frequency;
	
	bool operator<(const Key &k) const {
		return frequency < k.frequency;
	}
};



string reArrangeString(string s) {
	priority_queue<Key>q;

	unordered_map<char, int> m;
	for(char c : s) m[c]++;

	for(auto it : m) {
		q.push(Key{it.first, it.second});
	}

	string res = "";

	Key prev {'#', -1};

	while(!q.empty()) {
		Key current = q.top();
		q.pop();

		res += current.letter;

		if(prev.frequency > 0) {
			q.push(prev);
		}

		(current.frequency)--;
		prev = current;
	}

	return res;

}

int main() {
	string str = "bbbaa";
	cout << reArrangeString(str);
	return 0;
}
