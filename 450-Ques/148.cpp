#include<bits/stdc++.h>
using namespace std;

/*
	Copy a singly linked list with random pointers		
*/			

/*
	Approach 1 - Constant Space;
	Time - O(N);
	Space - O(1);
*/		

ListNode* copyList(ListNode* head) {
	ListNode* ptr = head;

	while(ptr) {
		ListNode* clonedNode = new ListNode(ptr->val, ptr->next, NULL);
		ptr->next = clonedNode;
		ptr = ptr->next;
	}

	
	ptr = head;
	// Connect the random pointers
	while(ptr) {
		ListNode* clonedNode = ptr->next;
		if(ptr->random) {
			clonedNode->random = ptr->random->next;
		}
		ptr = ptr->next;
	}

	ptr = head;
	ListNode* clonedHead = head->next;
	// Reset the original list
	while(ptr) {
		ListNode* clonedNode = ptr->next;
		ptr->next = clonedNode->next;
		ptr = ptr->next;
		if(ptr) ptr->next = clonedNode->next;
	}

	return clonedNode;
}


/*
	Approach 2 - HashMap
	Time - O(N);
	Space - O(N);
*/		
ListNode* copyList(ListNode* head) {
	unordered_map<ListNode*, int>m;

	ListNode* ptr = head;

	while(ptr) {
		m[ptr] = new ListNode(ptr->val);
		ptr = ptr->next;
	}

	ptr = head;
	while(ptr) {
		m[ptr]->next = m[ptr->next];
		m[ptr]->random = m[ptr->random];
		ptr = ptr->next;
	}

	return m[head];
}

int main() {
	ListNode* copiedList = copyList(head);
	return 0;
}
