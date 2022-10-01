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
    int ans = 0;
    int depth(TreeNode * node){
        //left right root //postorder
        if(!node) return 0;
        
        int l = depth(node -> left);
        int r = depth(node -> right);
        
        if(l + r > ans) ans = l + r;
        
        return max(l + 1, r + 1);
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int x = depth(root);
        return ans;
    }
};

class Solution {
private:
    int ans = 0;
    
    int depth(TreeNode *node){
        if(!node) return 0;
        
        int l = depth(node -> left);
        int r = depth(node -> right);
        
        ans = max(ans, l + r);
        
        return max(l, r) + 1;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == NULL) return 0;
        
        // Find depths of left and right subtrees
        int leftDepth = depth(root->left);
        int rightDepth = depth(root->right);
        
        // Return largest diameter (maybe not through root)
        return max(ans, leftDepth + rightDepth);
    }
};