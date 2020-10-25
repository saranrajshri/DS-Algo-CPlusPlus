#include<bits/stdc++.h>
using namespace std;

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
	head->val = 1;
	head->next = NULL;
	head->prev = NULL;
	// add nodes to linked list
	push(head, 10);
	push(head, 20);
	push(head, 30);

	return head;
}

/*
	Pair Sum
	Approach - Two pointers
	Time - O(N);
	Space - O(1);
*/		

void pairSum(ListNode* head, int target) {
	ListNode* left = head;
	ListNode* right = head;	

	while(right->next) right = right->next;

	while(left && right && left != right && right->next != left) {
		if(left->val + right->val == target) {
			cout << left->val << " " << right->val << endl;
			left = left->next;
			right = right->prev;
		}else  if(left->val + right->val > target) right = right->prev;
		else left = left->next;
	}
}

int main() {
	ListNode* head = constructLinkedList();
	int target = 40;
	pairSum(head, target);
	return 0;
}