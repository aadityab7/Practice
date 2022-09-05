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
    bool hasCycle(ListNode *head) {
        //tortoise and hash problem 
        bool ans = false;
        
        //tortoise increments by one and hash by two
        //when they meet is the intersection point
        //how to check if they never meet
        //if tortoise -> next || hash -> next || hash -> next -> next == null then ans = false
        
        ListNode *tort;
        ListNode *hash;
        
        tort = head;
        hash = head;
        
        while((tort != NULL) && (hash != NULL) && (hash -> next != NULL)){
            tort = tort -> next;
            hash = hash -> next -> next;
            if(tort == hash){
                ans = true;
                break;
            }
        }
        
        return ans;
    }
};

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
    bool hasCycle(ListNode *head) {
        //tortoise and hash problem 
        
        // if(head == NULL){
        //     return false;
        // }
        
        bool ans = false;

        //tortoise increments by one and hash by two
        //when they meet is the intersection point
        //how to check if they never meet
        //if tortoise -> next || hash -> next || hash -> next -> next == null then ans = false
        
        ListNode *tort;
        ListNode *hash;
        
        tort = head;
        hash = head;
        
        while((hash != NULL) && (hash -> next != NULL)){
            tort = tort -> next;
            hash = hash -> next -> next;
            if(tort == hash){
                ans = true;
                break;
            }
        }
        
        return ans;
    }
};