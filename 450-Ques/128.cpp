#include<bits/stdc++.h>
using namespace std;

/*
	Remove duplicates from a sorted linked list	
*/		

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
	push(head, 4);
	push(head, 4);
	push(head, 5);

	return head;
}

/*
	Actual Solution
	Time - O(N);
	Space - O(1);
*/		

void removeDuplicates(ListNode* head) {
	ListNode* ptr = head;

	if(head == NULL) return;

	while(ptr->next) {
		if(ptr->val == ptr->next->val) {
			ptr->next = ptr->next->next;
		}else{
			ptr = ptr->next;
		}
	}
}


int main() {
	ListNode* head = constructLinkedList();

	removeDuplicates(head);
	traverse(head);
	return 0;
}