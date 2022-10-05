/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        //do level order traversal 
        queue<pair<TreeNode *, TreeNode *>> q;
        q.push({original, cloned});
        
        while(!q.empty()){
            TreeNode * node = q.front().first;
            TreeNode * curr = q.front().second;
            q.pop();
            
            if(node == target) return curr;
            
            if(node -> left) q.push({node -> left, curr -> left});
            
            if(node -> right) q.push({node -> right, curr -> right});
        }
        
        
        return NULL;
    }
};

class Solution {
public:
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if(original == target) return cloned;
        
        TreeNode * x = (original -> left) ? getTargetCopy(original -> left, cloned -> left, target) : NULL;
        
        if(x) return x;
        
        TreeNode * y = (original -> right) ? getTargetCopy(original -> right, cloned -> right, target) : NULL;
        
        if(y) return y;
        
        return NULL;
    }
};

//Store the ans in a variable
class Solution {
public:
    TreeNode * ans;
    
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        
        if(original == NULL) return NULL;
        
        if(original == target) ans = cloned;
        
        getTargetCopy(original -> left, cloned -> left, target);
        getTargetCopy(original -> right, cloned -> right, target);
        
        return ans;
    }
};