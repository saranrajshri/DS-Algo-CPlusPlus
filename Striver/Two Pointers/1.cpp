/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ptr = head;
        if(head == NULL) return NULL;
        
        while(ptr){
            Node* newNode = new Node(ptr->val, ptr->next, NULL);
            ptr->next = newNode;
            ptr = newNode->next;
        }
        
        ptr = head;
        Node* copyPointer;
        
        while(ptr) {
            copyPointer = ptr->next;
            if(ptr->random) {
                copyPointer->random = ptr->random->next;
            }
            ptr = copyPointer->next;
        }
        
        ptr = head;
        Node* headCopy = head->next;
        
        while(ptr) {
            copyPointer = ptr->next;
            ptr->next = copyPointer->next;
            ptr = ptr->next;
            
            if(ptr){
                copyPointer->next = ptr->next;
            }
        }
        return headCopy;
    }
};