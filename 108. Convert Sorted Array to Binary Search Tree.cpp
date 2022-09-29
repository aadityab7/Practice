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
    TreeNode* create_tree(vector<int>& arr, int start, int end){
        if(start > end) return NULL;
        int mid = (start + end) / 2;
        TreeNode * node = new TreeNode(arr[mid]);
        node -> left = create_tree(arr, start, mid - 1);
        node -> right = create_tree(arr, mid + 1, end);
        return node;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return create_tree(nums, 0, nums.size() - 1);
    }
};