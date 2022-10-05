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
    bool evaluateTree(TreeNode* root) {
        //post -> left right root
        //eval left then right then root
        
        if(root->val == 0 || root->val == 1) return root->val;
        
        int x = evaluateTree(root->left);
        int y = evaluateTree(root->right);
        
        if(root->val == 2) return x | y;
        
        return x & y;
    }
};


class Solution {
public:
    bool evaluateTree(TreeNode* root) {
       switch(root->val){
            case 0:
            case 1:
               return root->val;
            case 2:
               return evaluateTree(root->left) || evaluateTree(root->right);
            case 3:
               return evaluateTree(root->left) && evaluateTree(root->right); 
       }
        
        return 0;
    }
};