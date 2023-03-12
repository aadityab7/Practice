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