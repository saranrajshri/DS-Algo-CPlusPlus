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
	push(head, 30);
	push(head, 20);
	push(head, 40); 

	return head;
}

ListNode* rotate(ListNode* head, int k) {
	ListNode* ptr = head;

	while(ptr && k - 1 > 0) {
		ptr = ptr->next;
		k--;
	}

	ListNode* head2 = ptr->next;
	ptr->next = NULL;

	ListNode* ptr2 = head2;

	while(ptr2->next) {
		ptr2 = ptr2->next;
	}

	ptr2->next = head;
	head = head2;

	return head; 
}

int main() {
	ListNode* head = constructLinkedList();
	traverse(head);
	
	int k = 2;
	ListNode* newHead = rotate(head, k);	
	traverse(newHead);
	
	return 0;
}