//using the original function to update root -> left or right - 106 ms
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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* new_node = new TreeNode(val);
            return new_node;
        }

        if(val > root -> val) root -> right = insertIntoBST(root -> right, val);
        else root -> left = insertIntoBST(root -> left, val);


        return root;
    }
};


//using a helper function just to add a new node in place - 97 ms
class Solution {
    void helper(TreeNode* node, int val){
        if(node -> val > val){
            if(node -> left) helper(node -> left, val);
            else node -> left = new TreeNode(val);
        } 
        else{
            if(node -> right) helper(node -> right, val);
            else node -> right = new TreeNode(val);
        }
    }
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root == NULL){
            TreeNode* new_node = new TreeNode(val);
            return new_node;
        }

        helper(root, val);
        
        return root;
    }
};