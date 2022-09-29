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
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *node, *temp;
        
        while(!q.empty()){
            node = q.front();
            q.pop();
                
            temp = node -> left;
            node -> left = node -> right;
            node -> right = temp;
            
            if(node -> left){
                q.push(node -> left);
            }
            
            if(node -> right){
                q.push(node -> right);
            }
        }
        
        return root;
    }
};

//USE IN - BUILT swap() function
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        queue<TreeNode *> q;
        q.push(root);
        TreeNode *node, *temp;
        while(!q.empty()){
            node = q.front();
            q.pop();
            swap(node -> left, node -> right);
            if(node -> left){
                q.push(node -> left);
            }
            if(node -> right){
                q.push(node -> right);
            }
        }
        return root;
    }
};

//USING RECURSION
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root) return root;
        swap(root -> left, root -> right);
        invertTree(root -> left);
        invertTree(root -> right);
        return root;
    }
};