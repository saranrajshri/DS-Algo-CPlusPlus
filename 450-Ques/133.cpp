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

/*
	Solution
	Time - O(N);
	Space - O(1); // don't consider the result list
*/		

ListNode* intersectionOfTwoList(ListNode* head1, ListNode* head2) {
	ListNode* dummy = new ListNode();
	dummy->val = -1;
	dummy->next = NULL;

	ListNode* ptr1 = head1;
	ListNode* ptr2 = head2;
	ListNode* ptr3 = dummy;

	while(ptr1 && ptr2) {
		if(ptr1->val == ptr2->val) {
			ListNode* newNode = new ListNode();
			newNode->val = ptr2->val;
			newNode->next = NULL;

			ptr3->next = newNode;
			ptr3 = ptr3->next; 
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
		else if(ptr1->val < ptr2->val) {
			ptr1 = ptr1->next;
		}else if(ptr2->val > ptr1->val) {
			ptr2 = ptr2->next;
		}
	} 

	return dummy->next;
}


int main() {
	ListNode* head1 = constructLinkedList();
	ListNode* head2 = constructLinkedList();

	ListNode* head3 = intersectionOfTwoList(head1, head2);
	traverse(head3);
	return 0;
}