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
    TreeNode* searchBST(TreeNode* root, int val) {
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode *node = q.front();
            q.pop();
            
            if(node -> val == val) return node;
            
            if(node -> val < val){
                if(node -> right) q.push(node -> right);
                else return NULL;
            }
            else{
                if(node -> left) q.push(node -> left);
                else return NULL;
            }
        }
        
        return NULL;
    }
};


//SMALLER - but not faster
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root != NULL && root -> val != val){
            root = val > root -> val ? root -> right : root -> left;
        }
        
        return root;
    }
};