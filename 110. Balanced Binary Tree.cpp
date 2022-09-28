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
    int flag = 0;
    
    int fun(TreeNode *node){
        if(!node) return 0;
        
        //left right root 
        //postorder 
        
        int l = fun(node -> left);
        int r = fun(node -> right);
        
        if(abs(l - r) > 1) flag = 1;
        
        return max((l + 1), (r + 1));
    }
    
    bool isBalanced(TreeNode* root) {
        int x = fun(root);
        if(flag) return false;
        return true;
    }
};

/*
we can iteratively find if each node is balanced or not
*/