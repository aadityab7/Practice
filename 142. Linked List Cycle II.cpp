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
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head, *fast = head;

        while(fast && fast -> next){
            slow = slow -> next;
            fast = fast -> next -> next;

            if(slow == fast){
                //cycle exists so find where it starts 
                ListNode * entry = head;
        
                //both move one step at a time and when they meet that's the starting point
                while(slow != entry){
                    entry = entry -> next;
                    slow = slow -> next;
                }

                return entry;
            }
        }

        return NULL;
    }
};