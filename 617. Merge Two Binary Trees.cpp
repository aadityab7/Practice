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
private:
    TreeNode* merge(TreeNode *node, TreeNode *node2){
        //preorder left right root
        
        if(node == NULL && node2 == NULL) return NULL;
        
        if(node == NULL) return node2;
        if(node2 == NULL) return node;
        
        TreeNode * temp = new TreeNode(node -> val + node2 -> val);
        
        temp -> left = merge(node -> left, node2 -> left);
        temp -> right = merge(node -> right, node2 -> right);
        
        return temp;
        
                
    }
public:
    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        return merge(root1, root2);
    }
};

//LITTLE SHORTER
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* node, TreeNode* node2) {
        if(!node && !node2) return NULL;
        
        if(!node) return node2;
        if(!node2) return node;
        
        TreeNode * temp = new TreeNode(node -> val + node2 -> val);
        
        temp -> left = mergeTrees(node -> left, node2 -> left);
        temp -> right = mergeTrees(node -> right, node2 -> right);
        
        return temp;
    }
};