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

ListNode* removeNthNode(ListNode* head, int n) {
	ListNode* fast = head;
	ListNode* slow = head;

	if(head == NULL) return NULL;
	if(head->next == NULL) return NULL;

	while(fast && n > 0) {
		fast = fast->next;
		n--;
	}

	if(fast == NULL)  return head->next;

	while(fast->next && slow->next) {
		fast = fast->next;
		slow = slow->next;
	}

	slow->next = slow->next->next;

	return head;
}

int main() {
	ListNode* head = constructLinkedList();
	traverse(head);
	ListNode* newHead = removeNthNode(head, 2);	
	traverse(newHead);
	return 0;
}