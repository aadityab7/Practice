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
    // bool ans = false;
    
    bool fun(TreeNode *node, int req){
        if(!node) return false;
        
        int x = req - node -> val;
        
        if(node -> left == NULL && node -> right == NULL){
            //it is the leaf node 
            //check if x == 0
            if(x == 0){
                // ans = true;
                return true;
            }
            else{
                return false;
            }
        }
        
        //not a leaf node
        return fun(node -> left, x) || fun(node -> right, x);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return fun(root, targetSum);
    }
};

//0ms
class Solution {
public:
    bool fun(TreeNode *node, int req){
        if(!node) return false;
        int x = req - node -> val;
        if(node -> left == NULL && node -> right == NULL){
            return (x == 0);
        }
        return fun(node -> left, x) || fun(node -> right, x);
        
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        return fun(root, targetSum);
    }
};