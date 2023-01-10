//0 ms
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
    bool helper(TreeNode* p, TreeNode *q){
        if(p && q) return helper(p -> left, q -> left) && (p-> val == q -> val) && helper(p -> right, q -> right);
        else if(!p && !q) return true;
        else return false;
    }
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return helper(p, q);
    }
};

// 0 ms
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p && q) return isSameTree(p -> left, q -> left) && (p-> val == q -> val) && isSameTree(p -> right, q -> right);
        else if(!p && !q) return true;
        else return false;
    }
};