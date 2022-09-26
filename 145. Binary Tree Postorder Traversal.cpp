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
    
    void postorder(TreeNode *node){
        if(node == NULL) return;
        
        //left right root;
        postorder(node -> left);
        postorder(node -> right);
        ans.push_back(node -> val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        postorder(root);
        return ans;
    }
};


//USING STACK
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root == NULL) return ans;
        
        stack<TreeNode *> stack;
        stack.push(root);
        
        while(!stack.empty()){
            TreeNode *curr = stack.top();
            
            if(curr == NULL){
                stack.pop();
                ans.push_back(stack.top() -> val);
                stack.pop();
            }
            else{
                stack.push(NULL);
            
                if(curr -> right != NULL){
                    stack.push(curr -> right);
                }

                if(curr -> left != NULL){
                    stack.push(curr -> left);
                }
            }
        }
              
        return ans;
    }
};