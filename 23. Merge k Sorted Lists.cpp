//HARD
//1382 ms

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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *prev = new ListNode(0);
        ListNode *head = prev;
        
        //keep going through all the lists 
        int min;
        
        while(true){
            min = -1;
            
            //find the smallest node;
            for(int i = 0; i < lists.size(); i++){
                
                if(lists[i]){
                    if(min == -1) min = i;
                    else if(lists[i] -> val < lists[min] -> val){
                        min = i;
                    }
                }
                
            }
            
            //no more elements present 
            if(min == -1) break;
            
            prev -> next = lists[min];
            prev = lists[min];
            
            lists[min] = lists[min] -> next;
            
        }
        
        return head -> next;
    }
};


//45 ms
typedef pair<int, ListNode*> pi;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *prev = new ListNode(0);
        ListNode *head = prev;
        
        //USING A PRIORITY QUEUE - MIN HEAP
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        
        for(int i = 0; i < lists.size(); i++){
            if(lists[i]) pq.push({lists[i] -> val, lists[i]});
        }
        
        while(!pq.empty()){
            //get the minimum node
            ListNode *node = pq.top().second;
            pq.pop();
            
            prev -> next = node;
            prev = prev -> next;
            node = node -> next;
            
            if(node) pq.push({node -> val, node});
        }
        
        return head -> next;
    }
};