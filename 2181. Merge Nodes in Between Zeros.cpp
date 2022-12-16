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
    ListNode* mergeNodes(ListNode* head) {
        ListNode *h = NULL, *c = NULL; 
        int sum = 0;

        head = head -> next;

        while(head){
            if(head -> val == 0){
                //create a new node and put it as curr -> next and then update curr;

                ListNode *t = new ListNode(sum);
                sum = 0;

                if(c) c -> next = t;
                else h = t;
                
                c = t;
            }

            sum += head -> val;
            head = head -> next;
        }

        return h;
    }
};