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
private:
    int total = 0;
    
    int sum(TreeNode * node){
        if(!node) return 0;
        
        int l = sum(node -> left);
        int r = sum(node -> right);
        
        total += abs(l - r);
        
        return (l + r + node -> val);
    }

public:
    int findTilt(TreeNode* root) {
        int x = sum(root);
        return total;
    }
};