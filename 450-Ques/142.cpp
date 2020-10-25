#include<bits/stdc++.h>
using namespace std;

/*
 	Doubly Linked List
 */		 

// Node Structure

struct ListNode {
	int val;
	struct ListNode* prev;
	struct ListNode* next; 
};

// Create a new Node
ListNode* createNewNode(int val) {
	ListNode* newNode = new ListNode();
	newNode->val = val;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

// Add a new node to the end of the list
void push(ListNode* head, int val) {
	ListNode* ptr = head;

	while(ptr->next) {
		ptr = ptr->next;
	}

	ListNode* newNode = createNewNode(val); 
	ptr->next = newNode;
	newNode->prev = ptr;

	ptr = ptr->next;
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

// Reverse Traverse the list
void reverseTraverse(ListNode* head) {
	ListNode* ptr = head;
	ListNode* tail = NULL;

	// Find the tail Node
	while(ptr->next) {
		ptr = ptr->next;
	}
	tail = ptr;

	// Reverse traversal
	while(tail) {
		cout << tail->val << " ";
		tail = tail->prev;
	}

	cout << endl;
}

// Shell Function
ListNode* constructLinkedList() {
	ListNode* head = new ListNode();
	head->val = 1;
	head->next = NULL;
	head->prev = NULL;
	// add nodes to linked list
	push(head, 1);
	push(head, 2);
	push(head, 3);
	push(head, 4);
	push(head, 10);
	push(head, 20);

	return head;
}

/*
	Solution
	Time - O(N ^ 2);
	Space - O(1);
*/		

int findPair(ListNode* left, ListNode* right, int target) {
	int count = 0;
	while(left && right && left != right && right->next = left){
		int currentSum = left->val + right->val;
		if(sum == target) {
			count++;
			left = left->next;
			right = right->prev;
		}else if(sum > target) {
			right = right->prev;
		}else{
			left = left->next;
		}
	}

	return count;
} 

void countTriplets(ListNode* head, int target) {
	ListNode* current = head;
	ListNode* left = NULL, right = NULL;	
	int count = 0;

	// Find the tail node
	current = head;
	while(current->next) current = current->next;
	right = current;

	// Reset
	current = head;
	
	// Actual Logic 
	while(current) {
		left = current->next;

		count += findPair(left, right, target - current->val);

		current = current->next;
	}

	cout << count << endl;
}

int main() {
	ListNode* head = constructLinkedList();
	int target = 9;
	countTriplets(head, target);
	return 0;
}