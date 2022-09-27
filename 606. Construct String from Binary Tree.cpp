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
    string ans = "";
    
    void preorder(TreeNode *node){
        //root left right
        if(!node) return;
        
        ans += to_string(node -> val);
        
        if(node -> left || node -> right)   ans += '(';
        preorder(node -> left);
        if(node -> left || node -> right)   ans += ')';
        
        
        if(node -> right)   ans += '(';
        preorder(node -> right);
        if(node -> right)   ans += ')';
        
    }
    
    string tree2str(TreeNode* root) {
        preorder(root);
        return ans;
    }
};