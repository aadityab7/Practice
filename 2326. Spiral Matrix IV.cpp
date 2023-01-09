//254 ms
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
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m, vector<int>(n, -1));

        int minx = 0, miny = 1, maxx = n - 1, maxy = m - 1;
        vector<int> nextx = {0, 1, 0, -1}, nexty = {1, 0, -1, 0};
        
        int dir = 0, i = 0, j = 0;

        while(head){
            ans[i][j] = head -> val;

            if(dir == 0 && j == maxx){
                dir = 1;
                maxx--;
            } 
            else if(dir == 1 && i == maxy){
                dir = 2;
                maxy--;
            } 
            else if(dir == 2 && j == minx){
                dir = 3;
                minx++;
            }
            else if(dir == 3 && i == miny){
                dir = 0;
                miny++;
            }

            i += nextx[dir];
            j += nexty[dir];
            head = head -> next;
        }

        return ans;
    }
};