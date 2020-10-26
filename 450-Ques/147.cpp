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
	push(head, 2);
	push(head, 1);
	push(head, 0);
	push(head, 1);
	push(head, 2);


	return head;
}

ListNode* createNewNode(int val) {
	ListNode* newNode = new ListNode();
	newNode->val = val;
	newNode->next = NULL;

	return newNode;
}

/*
	Time - O(N);
	Space - O(1);
*/		

ListNode* sortZeroOneTwoList(ListNode* head) {
	ListNode* ptr = head;
	ListNode* onesD = createNewNode(0);
	ListNode* twosD = createNewNode(0);
	ListNode* zerosD = createNewNode(0);

	ListNode* onesHead = onesD;
	ListNode* twosHead = twosD;
	ListNode* zerosHead = zerosD;

	while(ptr) {
		if(ptr->val == 0) {
			zerosD->next = ptr;
			ptr = ptr->next;
			zerosD = zerosD->next;
		}else if(ptr->val == 1) {
			onesD->next = ptr;
			ptr = ptr->next;
			onesD = onesD->next;
		}
		else{
			twosD->next = ptr;
			ptr = ptr->next;
			twosD = twosD->next;
		}
	}

	zerosD->next = onesHead->next ? onesHead->next : twosHead->next;
	onesD->next = twosHead->next;
	twosD->next = NULL;

	head = zerosHead->next;

	delete zerosD;
	delete onesD;
	delete twosD;

	return head;
}

int main() {
	ListNode* head = constructLinkedList();
	ListNode* newHead = sortZeroOneTwoList(head);

	traverse(newHead);
	return 0;
}