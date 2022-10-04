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
    TreeNode * prev = NULL;
    TreeNode * ans = NULL;
    //left node right
    void inorder(TreeNode *node){
        if(!node) return;
        
        inorder(node -> left);
        
        //set the right of prev node = curr
        //and curr left = null
        if(prev) prev -> right = node;
        else ans = node;
        
        prev = node;
        
        node -> left = NULL;
        
        inorder(node -> right);
    }
public:
    TreeNode* increasingBST(TreeNode* root) {
        //do inorder traversal and delete the original tree
        inorder(root);
        return ans;
    }
};