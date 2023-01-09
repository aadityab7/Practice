//28 ms
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
    TreeNode* helper(TreeNode* node, int target){
        //delete the leaf node
        if(!node) return NULL;

        node -> left = helper(node -> left, target);
        node -> right = helper(node -> right, target);

        if(node -> val == target && node -> left == NULL && node -> right == NULL){
            return NULL;
        }

        return node;
    }

public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return helper(root, target);
    }
};


//using the same function for recursion - 23 ms
class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root == NULL) return NULL;

        root -> left = removeLeafNodes(root -> left, target);
        root -> right = removeLeafNodes(root -> right, target);

        if(root -> val == target && root -> left == NULL && root -> right == NULL)
            return NULL;

        return root;
    }
};