#include<bits/stdc++.h>
using namespace std;

class MedianFinder {
	priority_queue<int, vector<int>> maxHeap;
	priority_queue<int, vector<int>, greater<int>> minHeap;
public:
	void addNum(int x);
	double getMedian();
};

void MedianFinder::addNum(int x) {
	if(maxHeap.empty() || maxHeap.top() > x) maxHeap.push(x);
	else minHeap.push(x);

	if(maxHeap.size() > minHeap.size() + 1) {
		maxHeap.push(minHeap.top());
		minHeap.pop();
	}
	else if(minHeap.size() > maxHeap.size() + 1) {
		minHeap.push(maxHeap.top());
		maxHeap.pop();
	}
}

double MedianFinder::getMedian() {
	if(maxHeap.size() == minHeap.size()) {
		return maxHeap.size() == 0 ? 0 : (maxHeap.top() + minHeap.top()) / 2.0;
	}
	else {
		return maxHeap.size() > minHeap.size() ? maxHeap.top() : minHeap.top();
	}
	return -1.0;
}

int main() {
	MedianFinder m;
	m.addNum(2);
	m.addNum(3);
	m.addNum(4);
	cout << m.getMedian() << endl;
	return 0;	
}
