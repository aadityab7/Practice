//By reversing the later half of list
class Solution {
public:
    int pairSum(ListNode* head) {
        //reverse the later half of list 
        int ans = 0;

        ListNode *slow = head, *fast = head;
        
        //get the mid point of list
        while(fast){
            fast = fast -> next -> next;
            slow = slow -> next;
        }

        //reverse the later half
        ListNode *prev = NULL, *next;

        while(slow){
            next = slow -> next;
            slow -> next = prev;
            prev = slow;

            cout << prev -> val << '\n';
            slow = next;
        }

        ListNode *temp = head;

        while(prev){
            ans = max(ans, temp -> val + prev -> val);
            temp = temp -> next;
            prev = prev -> next;
        }

        return ans;
    }
};

//fastest - 260 ms
class Solution {
public:
    int pairSum(ListNode* head) {
        int ans = 0;

        vector<int> arr;

        while(head){
            arr.push_back(head -> val);
            head = head -> next;
        }

        int n = arr.size();

        for(int i = 0; i < n / 2; i++)
            ans = max(ans, arr[i] + arr[n - i - 1]);

        return ans;
    }
};