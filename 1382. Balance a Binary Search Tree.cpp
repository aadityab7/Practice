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
    vector<TreeNode*> sortedArray;

    void inorder(TreeNode* node){
        if(node == NULL) return;

        inorder(node -> left);
        sortedArray.push_back(node);
        inorder(node -> right);
    }

    TreeNode* arrayToTree(int start, int end){
        if(start > end) return NULL;

        int mid = start + ((end - start) / 2);

        sortedArray[mid] -> left = arrayToTree(start, mid - 1);
        sortedArray[mid] -> right = arrayToTree(mid + 1, end);

        return sortedArray[mid];
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return arrayToTree(0, sortedArray.size() - 1);
    }
};