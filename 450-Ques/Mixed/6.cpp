#include<bits/stdc++.h>
using namespace std;

class kStacks {
	vector<int> nextIndex;
	vector<int> stackData;
	vector<int> topIndex;
	int nextAvailable;
public:
	kStacks(int k, int n);
	void push(int value, int kNumber);
	int pop(int kNumber);
};

kStacks::kStacks(int k, int n) {
	for(int i = 0; i < k; i++) topIndex.push_back(-1);

	for(int i = 0; i < n - 1; i++) nextIndex.push_back(i + 1);
	nextIndex[n - 1] = -1;
	
	for(int i = 0; i < n; i++) stackData.push_back(0);

	nextAvailable = 0;
}

void kStacks::push(int value, int kNumber) {
	if(kNumber < 0 || kNumber >= topIndex.size()) return;
	if(nextAvailable < 0) return;

	int currentIndex = nextAvailable;

	nextAvailable = nextIndex[currentIndex];
	stackData[currentIndex] = value;
	nextIndex[currentIndex] = topIndex[kNumber];
	topIndex[kNumber] = currentIndex;
} 

int kStacks::pop(int kNumber) {
	if(kNumber < 0 || kNumber >= topIndex.size() || topIndex[kNumber] < 0) return -1;

	int currentIndex = topIndex[kNumber];
	int value = stackData[currentIndex];
	topIndex[kNumber] = nextIndex[currentIndex];
	nextIndex[currentIndex] = nextAvailable;
	nextAvailable = currentIndex;

	return value;
}	

int main() {
	int k = 3;
	int n = 10;

	kStacks ks(k, n);
	ks.push(15, 2);
    ks.push(45, 2);
  
    // Let us put some items in stack number 1
    ks.push(17, 1);
    ks.push(49, 1);
    ks.push(39, 1);
  
    // Let us put some items in stack number 0
    ks.push(11, 0);
    ks.push(9, 0);
    ks.push(7, 0);
  
    cout << "Popped element from stack 2 is " << ks.pop(2) << endl;
    cout << "Popped element from stack 1 is " << ks.pop(1) << endl;
    cout << "Popped element from stack 0 is " << ks.pop(0) << endl;
  
	return 0;	
}
