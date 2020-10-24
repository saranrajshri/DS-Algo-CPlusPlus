#include<bits/stdc++.h>
using namespace std;

/*
	Delete a loop from SLL
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
	push(head, 30);
	push(head, 20);
	push(head, 40);
	head->next->next = head; 

	return head;
}

/*
	Problem - Detect a loop
	Approach - Floyd Algorithm

	Time - O(N);
	Space - O(1);
*/		


ListNode* detectLoop(ListNode* head) {
	ListNode* fast = head;
	ListNode* slow = head;
	ListNode* middle = NULL;

	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;

		if(fast == slow) {
			middle = fast;
			break;
		}	
	}

	ListNode* runner = head;
	while(runner && middle) {
		
		if(runner == middle) return runner;

		runner = runner->next;
		middle = middle->next;

	}

	return NULL;
}

/*
	Actual solution here

	Approach 1
	Time - O(N);
	Space - O(1);
*/		

ListNode* deleteLoop(ListNode* head, ListNode* loopHead) {
	int k = 1;
	ListNode* ptr1 = loopHead;
	ListNode* ptr2 = loopHead;

	while(ptr1->next != ptr2){
		ptr1 = ptr1->next;
		k++;
	}
	
	ptr1 = ptr2 = head;

	while(k--) {
		ptr2 = ptr2->next;
	}

	while(ptr1 != ptr2) {
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	while(ptr2->next != ptr1) {
		ptr2 = ptr2->next;
	}

	ptr1->next = NULL;

	return head;
}

/*
	Appproach 2 
	Much Simpler
*/		

ListNode* deleteLoop(ListNode* head, ListNode* loopHead) {
	ListNode* ptr = head;

	while(ptr->next != loopHead->next) {
		ptr = ptr->next;
		loopHead = loopHead->next;
	}

	ptr->next = NULL;

	return head;
}



int main() {
	ListNode* head = constructLinkedList();
	
	ListNode* loopNode = detectLoop(head);
	if(loopNode) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}

	ListNode* modifiedHead = deleteLoop(head, loopNode);	
	ListNode* loopHead2 = detectLoop(modifiedHead);

	if(loopHead2) {
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}


	return 0;
}