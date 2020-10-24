#include<bits/stdc++.h>
using namespace std;

/*
	Singly Linked List
*/		

// Node Structure
struct ListNode{
	int val;
	struct ListNode* next;
};

// Add a new Node at the end
void push(ListNode* head, int data) {
	ListNode* ptr = head;

	ListNode* newNode = new ListNode();
	newNode->val = data;
	newNode->next = NULL;

	while(ptr->next != NULL) {
		ptr = ptr->next;
	}
	ptr->next= newNode;
}

// Delete the tail node
void deleteTailNode(ListNode* head){
	ListNode* ptr = head;

	while(ptr->next->next != NULL) {
		ptr = ptr->next;
	}	
	ListNode* temp = ptr->next; // LastNode
	ptr->next = NULL;

	delete temp;
}

// Delete a node by its value
void deleteByValue(ListNode* head, int data) {
	ListNode* ptr = head;

	while(ptr->next) {
		if(ptr->next->val == data) break;
		ptr = ptr->next;
	}
	ListNode* temp = ptr->next;
	ptr->next = ptr->next->next;

	delete temp;
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

// Shell Function
ListNode* constructLinkedList() {
	ListNode* head = new ListNode();
	head->val = 1;
	head->next = NULL;

	// add nodes to linked list
	push(head, 1);
	push(head, 2);
	push(head, 2);
	push(head, 4);
	push(head, 5);
	push(head, 6);
	push(head, 7);
	push(head, 8);

	return head;
}

/*
	Approach - Iterative + Recursive
	Time - O(n);
	Space - O(n / k); // call stack
*/	

ListNode* reverseListOfSizeK(ListNode* head, int k) {
	ListNode* prev = NULL;
	ListNode* curr = head;
	ListNode* next = NULL;
	int count = 0;

	while(curr && count < k) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
		count++;
	}

	// now the next pointer will be at  k + 1 th node,
	if(next != NULL) {
		head->next = reverseListOfSizeK(next, k);
	}

	return prev;
}


int main() {
	ListNode* head = constructLinkedList();
	int k = 4;

	ListNode* reversedListNode = reverseListOfSizeK(head, k);
	traverse(reversedListNode);

	return 0;
}