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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //remove nth from last or remove size - n + 1 th from front
        //calc size;
        int size = 0;
        ListNode *temp = head;
        
        while(temp != NULL){
            size ++;
            temp = temp -> next;
        }
        
        if(n == size) return head -> next;
        
        //we have size
        //remove the size - n + 1th node
        //go to size - n th node and remove the next node;
        temp = head;
        for(int i = 1; i < size - n; i++){
            temp = temp -> next;
        }
        
        ListNode * del = temp -> next;
        
        //remove temp -> next
        if(del != NULL){
            temp -> next = del -> next;
        }
        
        delete(del);
        return head;
    }
};

//TWO POINTER 
//FAST APPROACH
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //using two pointer approach
        ListNode *slow, *fast;
        slow = fast = head;
        
        //move fast pointer n steps ahead
        while(n--) fast = fast -> next;
        
        //now we have difference of n nodes btw slow and fast
        
        //if fast is NULL then we have to delete head itself
        if(!fast) return head -> next;
        
        while(fast -> next){
            fast = fast -> next;
            slow = slow -> next;
        }
        
        //delete the node after the slow node
        slow -> next = slow -> next -> next;
        
        return head;
    }
};