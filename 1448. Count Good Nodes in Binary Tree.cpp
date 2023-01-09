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

    void helper(TreeNode* node, int mx){
        if(!node) return;

        if(node -> val >= mx){ 
            ans++;
            mx = node -> val;
        }

        helper(node -> left, mx);
        helper(node -> right, mx);
    }

public:
    int goodNodes(TreeNode* root) {
        helper(root, INT_MIN);
        return ans;
    }
};