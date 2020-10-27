#include<bits/stdc++.h>
using namespace std;

/*
	Merge Sort 
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
	push(head, 0);
	push(head, 120);
	push(head, 40);



	return head;
}

/*
	Time - O(n log N);
	Space - O(n);
*/		

ListNode* merge(ListNode* left, ListNode* right) {
	ListNode* dummy = new ListNode();
	dummy->val = -1;
	dummy->next = NULL;

	ListNode* ptr = dummy;

	while(left && right) {
		if(left->val < right->val) {
			ptr->next = left;
			left = left->next;
		}else{
			ptr->next = right;
			right = right->next;
		}

		ptr = ptr->next;

		if(left) {
			ptr->next = left;
		}else{
			ptr->next = right; 
		}
	} 

	return dummy->next;
}

ListNode* mergeSort(ListNode* head) {
	if(head == NULL || head->next == NULL) return head;
	ListNode* fast = head->next->next;
	ListNode* slow = head;

	while(fast && fast->next) {
		fast = fast->next->next;
		slow = slow->next;
	}

	ListNode* rightList = mergeSort(slow->next);
	slow->next = NULL;
	ListNode* leftList = mergeSort(head);

	return merge(leftList, rightList);

}

int main() {
	ListNode* head = constructLinkedList();
	traverse(head);

	ListNode* sortedListHead = mergeSort(head);
	traverse(sortedListHead);
	return 0;
}