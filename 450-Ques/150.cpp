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
	push(head, 3);
	push(head, 2);
	push(head, 4);


	return head;
}

int multiplyList(ListNode* head1, ListNode* head2) {
	ListNode* ptr1 = head1;
	ListNode* ptr2 = head2;
	int num1 = 0, num2 = 0;

	while(ptr1 || ptr2) {
		if(ptr1) {
			num1 = num1 * 10 + ptr1->val;
			ptr1 = ptr1->next;
		}
		if(ptr2) {
			num2 = num2 * 10 + ptr2->val;
			ptr2 = ptr2->next;
		}
	}

	return num1 * num2;
}


int main() {
	ListNode* head1 = constructLinkedList();
	ListNode* head2 = constructLinkedList();

	cout << multiplyList(head1, head2);
	return 0;
}