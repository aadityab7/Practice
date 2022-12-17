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
int ans = 0;

pair<int, int> dfs(TreeNode *node){
    if(!node) return {0, 0};

    pair<int, int> l = dfs(node -> left);
    pair<int, int> r = dfs(node -> right);
    
    int sum = node -> val + l.first + r.first;
    int n = 1 + l.second + r.second;
   
    if(node -> val == (sum / n)) ans++;

    return {sum, n};
}

public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};