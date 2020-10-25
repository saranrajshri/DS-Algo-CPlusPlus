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
	Problem Intersection Point of two linked lists
*/		

int length(ListNode* head) {
	int count = 1;
	ListNode* ptr = head;

	while(ptr->next) {
		ptr = ptr->next;
		count++;
	}

	return count;
}

ListNode* intersectionPoint(ListNode* head1, ListNode* head2) {
	int list1Length = length(head1);
	int list2Length = length(head2);

	int difference = abs(head2 - head1);
	ListNode* ptr1 = head1;
	ListNode* ptr2 = head2;

	// move d nodes in list 1
	if(list1Length > list2Length) {
		while(ptr1 && difference--) {
			ptr1 = ptr1->next;
		}
	}
	// mode d nodes in list 2
	else{
		while(ptr2 && difference--) {
			ptr2 = ptr2->next;
		}
	}

	// iterate both lists
	while(ptr1 && ptr2) {
		if(ptr1 == ptr2) return ptr1;
		else{
			ptr1 = ptr1->next;
			ptr2 = ptr2->next;
		}
	}

	return NULL;
}

int main() {
	ListNode* head = constructLinkedList();
	return 0;
}