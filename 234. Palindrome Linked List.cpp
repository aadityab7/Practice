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
    bool isPalindrome(ListNode* head) {
        //create a array 
        //calculate size 
        int size = 0;
        ListNode* temp = head;
        
        while(temp != NULL){
            size++;
            temp = temp -> next;
        }
        
        //we know the size
        //n = size / 2
        
        vector<int> arr;
        temp = head;
        for(int i = 0; i < size / 2; i++){
            arr.push_back(temp -> val);
            temp = temp -> next;
        }
        
        if(size % 2){
            //add elements till n / 2 and then skip one 
            temp = temp -> next;
        }
        
        //now check if all the elements exist in the array in reverse order
        for(int i = (size / 2) - 1; i >= 0; i--){
            if(arr[i] != temp -> val){
                return false;
            }
            
            temp = temp -> next;
            
        }
        
        return true;
    }
};


class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev, *temp;
        
        while (fast && fast->next)
            slow = slow->next, fast = fast->next->next;
        
        prev = slow, slow = slow->next, prev->next = NULL;
        
        while (slow)
            temp = slow->next, slow->next = prev, prev = slow, slow = temp;
        
        fast = head, slow = prev;
        while (slow)
            if (fast->val != slow->val) return false;
            else fast = fast->next, slow = slow->next;
        
        return true;
    }
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
//  */
// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         ListNode *slow, *fast;
//         slow = fast = head;
//         ListNode *prev = NULL;
    
//          //finding the middle 
//         while(fast && fast -> next){
//             prev = slow;
//             fast = fast -> next -> next;
//             slow = slow -> next;
//         }
        
//         //now slow points to the middle node
        
//         //reverse the linked list starting from middle 
//         // ListNode *prev;
//         ListNode *next;
//         if(prev != NULL){
//              prev -> next = NULL;
//         }
       
        
//         while(slow){
//             next = slow -> next;
//             slow -> next = prev;
//             prev = slow;
//             slow = next;
//         }
        
//         //Later half of Linked list is reversed
//         slow = prev;
//         fast = head;
        
// //         while(slow){
// //             cout << slow -> val << ' ';
// //             slow = slow -> next;
// //         }
        
// //         while(fast){
// //             cout << fast -> val << ' ';
// //             fast = fast -> next;
// //         }
        
//         while(fast != NULL){
//             if(fast -> val != slow -> val){
//                 return false;
//             }
            
//             fast = fast -> next;
//             slow = slow -> next;
//         }
        
//         return true;
        
        
//     }
// };