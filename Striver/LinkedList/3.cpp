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
	push(head, 20);
	push(head, 30);
	push(head, 40); 

	return head;
}

ListNode* merge(ListNode* head1, ListNode* head2) {
	ListNode* dummy = new ListNode();
	dummy->next = NULL;
	dummy->val = -1;

	ListNode* ptr = dummy;
	ListNode* ptr1 = head1;
	ListNode* ptr2 = head2;

	while(ptr1 && ptr2) {
		if(ptr1->val < ptr2->val) {
			ptr->next = ptr1;
			ptr1 = ptr1->next;
		}else{
			ptr->next = ptr2;
			ptr2 = ptr2->next;
		}
		ptr = ptr->next;
	}

	ptr->next = ptr1 ? ptr1 : ptr2; 

	return dummy->next;
}

int main() {
	ListNode* head = constructLinkedList();
	ListNode* head1 = constructLinkedList();

	ListNode* mergedHead = merge(head, head1);

	traverse(mergedHead);
	return 0;
}