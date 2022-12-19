//0 ms - using upper and lower bounds (min and max)
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
int index = 0;

TreeNode * helper(int min, int max, const vector<int>& arr){
    if(index == arr.size() || arr[index] < min || arr[index] > max) return NULL;

    TreeNode *node = new TreeNode(arr[index]);

    index++;

    node -> left = helper(min, node -> val, arr);

    node -> right = helper(node -> val, max, arr);

    return node;
}

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(INT_MIN, INT_MAX, preorder);
    }
};

//we actually only need maximum bound to shift to right tree when left is done - 0 ms
//it marks the end of left subtree
class Solution {
int index = 0;

TreeNode * helper(int max, const vector<int>& arr){
    if(index == arr.size() || arr[index] > max) return NULL;

    TreeNode *node = new TreeNode(arr[index]);

    index++;

    node -> left = helper(node -> val, arr);
    node -> right = helper(max, arr);

    return node;
}

public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return helper(INT_MAX, preorder);
    }
};