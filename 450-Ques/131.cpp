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
	head->val = 4;
	head->next = NULL;

	// add nodes to linked list
	push(head, 5);
	push(head, 6);

	return head;
}

// reverse the list
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
	Approach - Reverse and traverse
	Time - O(N);
	Space - O(1);	
*/		

	
ListNode* addOne(ListNode* head) {
	ListNode* newHead = reverseLinkedList(head);
	ListNode* ptr = newHead;

	int carry = 1;
	int sum = 0;
	ListNode* temp = NULL;

	while(ptr) {
		sum = ptr->val + carry;

		carry = (sum >= 10) ? 1 : 0;

		sum = sum % 10;

		ptr->val = sum;

		temp = ptr;
		ptr = ptr->next;
	}

	while(carry > 0) {
		ListNode* newNode = new ListNode();
		newNode->val = carry;
		newNode->next = NULL;
		
		temp->next = newNode;
	}

	return reverseLinkedList(newHead);
}

int main() {
	ListNode* head = constructLinkedList();
	ListNode* newHead = addOne(head);
	
	traverse(newHead);
	return 0;
}