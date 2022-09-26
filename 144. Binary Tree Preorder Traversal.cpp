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
    vector<int> ans;
    
    void preorder(TreeNode *node){
        
        if(node == NULL) return;
        
        ans.push_back(node -> val);
        preorder(node -> left);
        preorder(node -> right);
        
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        //impliment preorder traversal
        //root left right
        
        preorder(root);
        
        return ans;
    }
};

//USING STACK
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        if(root == NULL) return ans;
        
        stack<TreeNode*> stack;
        stack.push(root);
        
        while(!stack.empty()){
            
            TreeNode *curr = stack.top();
            stack.pop();
            
            ans.push_back(curr -> val);
            
            if(curr -> right != NULL){
                stack.push(curr -> right);
            }
            if(curr -> left != NULL){
                stack.push(curr -> left);
            }
            
        }
        
        return ans;
    }
};