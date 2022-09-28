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
    
    int depth(TreeNode *node){
        if(!node) return 0;
        
        int l = depth(node -> left);
        int r = depth(node -> right);
        
        if(l == 0) return r + 1;
        if(r == 0) return l + 1;
        
        return min(l + 1, r + 1);
    }
    
    int minDepth(TreeNode* root) {
        // if(root == NULL) return 0;
        // if(root -> left == NULL) return (depth(root -> right) + 1);
        // if(root -> right == NULL) return (depth(root -> left) + 1);
        return depth(root);
    }
};

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
    
   
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        int level = 0;
        queue<TreeNode *> q;
        q.push(root);
        int breadth;
        TreeNode *temp;
        
        while(!q.empty()){
            breadth = q.size();
            level++;
           
            for(int i = 0; i < breadth; i++){
                temp = q.front();
                q.pop();
                
                if(temp -> left) q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
                
                if(temp -> left == NULL && temp -> right == NULL) return level;
            }
        }
        
        return level;
        
    }
};