#include<bits/stdc++.h>
using namespace std;

/*
 	Doubly Linked List
 */		 

// Node Structure

struct ListNode {
	int val;
	struct ListNode* prev;
	struct ListNode* next; 
};

// Create a new Node
ListNode* createNewNode(int val) {
	ListNode* newNode = new ListNode();
	newNode->val = val;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

// Add a new node to the end of the list
void push(ListNode* head, int val) {
	ListNode* ptr = head;

	while(ptr->next) {
		ptr = ptr->next;
	}

	ListNode* newNode = createNewNode(val); 
	ptr->next = newNode;
	newNode->prev = ptr;

	ptr = ptr->next;
}

// Traverse the list
void traverse(ListNode* head) {
	ListNode* ptr = head;

	while(ptr) {
		cout << ptr->val << " ";
		ptr = ptr->next;
	}
	cout << endl;
}

// Reverse Traverse the list
void reverseTraverse(ListNode* head) {
	ListNode* ptr = head;
	ListNode* tail = NULL;

	// Find the tail Node
	while(ptr->next) {
		ptr = ptr->next;
	}
	tail = ptr;

	// Reverse traversal
	while(tail) {
		cout << tail->val << " ";
		tail = tail->prev;
	}

	cout << endl;
}

// Shell Function
ListNode* constructLinkedList() {
	ListNode* head = new ListNode();
	head->val = 3;
	head->next = NULL;
	head->prev = NULL;
	// add nodes to linked list
	push(head, 6);
	push(head, 12);
	push(head, 56);
	push(head, 8);

	return head;
}

/*
	
*/	

struct compare{
	bool operator()(ListNode* left, ListNode* right) {
		return left->val > right->val;
	}
}

ListNode* sortKLinkedList(ListNode* head, int k) {
	if(head == NULL) return NULL;

	priority_queue<ListNode*, vector<ListNode*>, comp>minHeap;
	ListNode* ptr = head;
	ListNode* newHead = NULL, lastNode = NULL;

	while(ptr && (k + 1)--) {
		minHeap.push(ptr->val);
		ptr = ptr->next;
	}

	ptr = head;

	while(!minHeap.empty()) {
		if(newHead == NULL) {
			newHead = minHeap.top();
			newHead->prev = NULL;
			last = newHead;
		}else{
			last->next = minHeap.top();
			minHeap.top()->prev = last;
			last = minHeap.top();
		}

		minHeap.pop();

		if(ptr != NULL) {
			minHeap.push(ptr);
			ptr = ptr->next;
		}
	}

	last->next = NULL;
	return newHead;
}

int main() {
	ListNode* head = constructLinkedList();
	ListNode* newHead = sortKLinkedList(head, 2);
	traverse(newHead);
	return 0;
}