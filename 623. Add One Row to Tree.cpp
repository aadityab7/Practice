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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode * node = new TreeNode(val);
            node -> left = root;
            return node;
        }
        
        queue<TreeNode *> q;
        q.push(root);
        int level = 0;
        
        while(!q.empty()){
            int s = q.size();
            level++;
            
            for(int i = 0; i < s; i++){
                TreeNode * node = q.front();
                q.pop();
                
                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);
                
                
                if(level == depth - 1){
                    //add node as left and add a node as right
                    
                    TreeNode * lnode = new TreeNode(val, node->left, NULL);
                    TreeNode * rnode = new TreeNode(val, NULL, node->right);
                    
                    node -> left = lnode;
                    node -> right = rnode;
                }
                
            }
            
        }
        
        return root;
    }
};