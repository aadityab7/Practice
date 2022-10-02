/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        long min = INT_MAX, min2 = INT_MAX;
        min++;
        min2++;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            
            if(node -> left){
                q.push(node -> left);
                q.push(node -> right);
            }
            else{
                if(node -> val < min){
                    min2 = min;
                    min = node -> val;
                }
                else if(node -> val < min2 && node -> val > min){
                    min2 = node -> val;
                }
            }
        }
        
        if(min2 > INT_MAX) return -1;
        return (int)min2;
    }
};