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
    ListNode* swapPairs(ListNode* head) {
        ListNode *f = head, *s, *t, *prev = NULL;
        
        while(f && f->next){
            
            s = f->next;
            
            if(prev) prev -> next = s;
            else head = s;
            
            f->next = s->next;
            s->next = f;
            
            prev = f;
            
            f = f -> next;
        }
        
        return head;
        
    }
};