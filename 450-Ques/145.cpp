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
	head->val = 1;
	head->next = NULL;
	head->prev = NULL;
	// add nodes to linked list
	push(head, 10);
	push(head, 20);
	push(head, 30);

	return head;
}

ListNode* reverseListInGrp(ListNode* head, int k) {
	ListNode* temp = NULL;
	ListNode* current = head;
	int count = 0;

	while(current && count < k) {
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		current = current->prev;
		count++;
	}

	if(head->next != NULL) {
		head->next = reverseListInGrp(head->next, 2);
		head->next->prev = head;
	}


	return current;
}

int main() {
	ListNode* head = constructLinkedList();
	ListNode* reversedHead = reverseListInGrp(head, 2);
	traverse(reversedHead);
	return 0;
}