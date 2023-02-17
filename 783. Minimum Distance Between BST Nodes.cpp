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
    TreeNode * prev = NULL;
    vector<int> arr;
    int ans = INT_MAX;
    
    void inorder(TreeNode * node){
        //left root right
        
        if(!node) return;
        
        inorder(node -> left);
        
        if(prev){
             ans = min(ans, node->val - prev->val);
        }

        prev = node;
        
        inorder(node -> right);
    }
    
public:
    int minDiffInBST(TreeNode* root) {
        //store elements in array and then check for min abs diff
        //just do inorder traversal and check for diff
        //keep track of prev node
        
        inorder(root);
        return ans;
    }
};