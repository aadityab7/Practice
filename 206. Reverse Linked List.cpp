/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        //start with the head maintain 3 pointers 
        //prev, curr and next
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = curr;
        
        // ListNode *prev = NULL, *curr = head, *next = head; 
        
        while(curr != NULL){
            next = curr -> next;
            
            // if(next == NULL){
            //     head = curr;
            // }
            
            curr -> next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
        
        return head;
        
    }
};