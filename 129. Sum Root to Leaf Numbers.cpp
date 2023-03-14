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
    int ans = 0;
    void leafSum(TreeNode *node, int curr_sum){
        curr_sum += node -> val;

        if(node -> left) leafSum(node -> left, curr_sum * 10);
        if(node -> right) leafSum(node -> right, curr_sum * 10);

        if(node -> left == NULL && node -> right == NULL) ans += curr_sum;    
    }

public:
    int sumNumbers(TreeNode* root) {
        leafSum(root, 0);
        return ans;    
    }
};