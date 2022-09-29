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
    int sum = 0;
    
    void left_leaf_sum(TreeNode *node, bool is_left){
        if(!node) return;
        
        if(is_left && (node -> left || node -> right)){
            //not leaf node and it's value has been added to sum;
            sum -= (node -> val);
        }
        
        if(node -> left){
            sum += node -> left -> val;
            left_leaf_sum(node -> left, true);
        }
        
        left_leaf_sum(node -> right, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root){
        left_leaf_sum(root, false);
        return sum;
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
    int left_leaf_sum(TreeNode *node, bool is_left){
        if(!node) return 0;
        
        if(is_left && (node -> left == NULL && node -> right == NULL)){
            return node -> val;
        }
        
        return left_leaf_sum(node -> left, true) + left_leaf_sum(node -> right, false);
    }
    
    int sumOfLeftLeaves(TreeNode* root){
        return left_leaf_sum(root, false);
    }
};