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
    bool trav(TreeNode * x, TreeNode * y){
        if(!x && !y) return true;
        else if(!x || !y) return false;
        return trav(x -> left, y -> right) && (x -> val == y-> val) && trav(x -> right, y -> left);
    }

public:
    bool isSymmetric(TreeNode* root) {
        return trav(root -> left, root -> right);
    }
};