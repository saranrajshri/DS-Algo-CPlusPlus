#include<bits/stdc++.h>
using namespace std;

/*
	Circular Linked List
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


    head->next->next->next = head;

	return head;
}

/*
	Solution
	Time - O(N);
	Space - O(1);
*/		

void splitList(ListNode* head) {
	ListNode* fast = head;
	ListNode* slow = head;

	ListNode* leftHead = NULL;
	ListNode* rightHead = NULL;

	while(fast->next != head && fast->next->next != head) {
		fast = fast->next->next;
		slow = slow->next;
	}

	if(fast->next->next == head) {
		fast = fast->next;
	}

	leftHead = head;

	if(head->next != head) {
		rightHead = slow->next;
	}

	fast->next = rightHead;
	slow->next = leftHead;

}

int main() {
	ListNode* head = constructLinkedList();
	splitList(head);
	
	return 0;
}