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
    int val;
    bool pre(TreeNode * node){
        if(!node) return true;
        
        if(node -> val != val) return false;
        
        return pre(node -> left) && pre(node -> right);
    }
    
public:
    bool isUnivalTree(TreeNode* root) {
        val = root -> val;
        return pre(root);
    }
};