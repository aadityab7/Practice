/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        //how to get prev node with singly linked list
        //prev -> next = node
        //prev -> next = node -> next;
        ListNode * prev = node;
        
        while(node -> next != NULL){
        
            node -> val = node -> next -> val;
            prev = node;
            node = node -> next;
            
        }
        
        //now we are at last node
        prev -> next = NULL;
    }
};

class Solution {
public:
    void deleteNode(ListNode* node) {
        //delete the next node instead of this one
        node -> val = node -> next -> val;
        node -> next = node -> next -> next;
    }
};