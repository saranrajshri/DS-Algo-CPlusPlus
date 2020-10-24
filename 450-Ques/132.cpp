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
	head->val = 9;
	head->next = NULL;

	// add nodes to linked list
	push(head, 3);
	push(head, 2);
	push(head, 1);


	return head;
}

/*
	Solution
	Time - O(N);
	Space - O(1)
*/


ListNode* addTwoLists(ListNode* head1, ListNode* head2) {
	ListNode* dummy = new ListNode();
	dummy->val = -1;
	dummy->next = NULL;

	ListNode* ptr1 = head1;
	ListNode* ptr2 = head2;
	ListNode* ptr3 = dummy;

	int carry = 0;
	int sum = 0;

	while(ptr1 && ptr2) {
		int p1Val = ptr1 ? ptr1->val : 0;
		int p2Val = ptr2 ? ptr2->val : 0;

		sum = p1Val + p2Val + carry;

		int lastDigit = sum % 10;

		carry = sum / 10;

		ListNode* newNode = new ListNode();
		newNode->val = lastDigit;
		newNode->next = NULL;

		ptr3->next = newNode;

		if(ptr1) ptr1 = ptr1->next;
		if(ptr2) ptr2 = ptr2->next;
		ptr3 = ptr3->next;
	}
	while(carry > 0) {
		ListNode* newNode = new ListNode();
		newNode->val = carry % 10;
		newNode->next = NULL;

		ptr3->next = newNode;
		ptr3 = ptr3->next;
		carry = carry / 10;
	}

	return dummy->next;
}

int main() {
	ListNode* head1 = constructLinkedList();
	ListNode* head2 = constructLinkedList();

	ListNode* newNode = addTwoLists(head1, head2);
	traverse(newNode);
	return 0;
}	