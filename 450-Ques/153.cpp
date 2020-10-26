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
	head->val = 12;
	head->next = NULL;

	// add nodes to linked list
	push(head, 15);
	push(head, 10);
	push(head, 11);
	push(head, 5);
	push(head, 6);
	push(head, 2);
	push(head, 3);

	return head;
}

ListNode* removeLargeAdjacent(ListNode* head) {
	ListNode* current = head;

	while(current->next) {
		if(current->val > current->next->val) {
			current->next = current->next->next;
			current = current->next;
		}
	}
}

int main() {
	ListNode* head = constructLinkedList();
	traverse(head);
	ListNode* newHead = removeLargeAdjacent(head);
	return 0;
}