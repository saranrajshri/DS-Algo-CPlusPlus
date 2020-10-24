#include<bits/stdc++.h>
using namespace std;

/*
	Singly Linked List
	Problem - Reverse a linked list
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
	push(head, 30);
	push(head, 20);
	push(head, 40);

	// traverse(head);
	// deleteByValue(head, 40);
	// traverse(head);
	// deleteTailNode(head);
	// traverse(head);

	return head;
}

/*
	Approach - Iterative;
	Time - O(N);
	Space - O(1);
*/ 
ListNode* reverseLinkedList(ListNode* head) {
	ListNode* prev = NULL;
	ListNode* curr = head;
	ListNode* next = NULL;

	while(curr) {
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	return prev;
}

/*
	Approach - Recursive
	Time - O(N);
	Space - O(N);
*/		

ListNode* reversedHead = NULL;

ListNode* reverseLinkedList(ListNode* node) {
	if(node == NULL) return NULL;

	// if it is the Last element, then it is the root;
	if(node->next == NULL) {
		reversedHead = node;
		return node;
	}

	ListNode* newNode = reverseLinkedList(node->next);
	newNode->next = node;
	node->next = NULL;

	return node;
}

// Shell Function
ListNode* reverseLinkedListShell(ListNode* head) {
	reverseLinkedList(head);

	return reversedHead;
}

int main() {
	ListNode* head = constructLinkedList();

	ListNode* tailNode = reverseLinkedList(head);
	traverse(tailNode);

	return 0;
}