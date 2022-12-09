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
        int min, max, num = node -> val;
        min = max = num;

        if(node -> left){
            pair<int, int> l = dfs(node -> left);

            if(l.first < min) min = l.first;
            if(l.second > max) max = l.second;
        }

        if(node -> right){
            pair<int, int> r = dfs(node -> right);
            
            if(r.first < min) min = r.first;
            if(r.second > max) max = r.second;
        }

        if(abs(num - min) > ans) ans = abs(num - min);
        if(abs(num - max) > ans) ans = abs(num - max);

        pair<int,int> res = {min, max};
        return res;
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

/*
    perform dfs - left right root
    return min and max values from each node
    at root comp min and max values
*/

class Solution {
    int dfs(TreeNode *node, int min, int max){
        if(node == NULL) return max - min;

        if(node -> val < min) min = node -> val;
        if(node -> val > max) max = node -> val;

        int l = dfs(node -> left, min, max);
        int r = dfs(node -> right, min, max);

        return (l > r) ? l : r;
    }

public:
    int maxAncestorDiff(TreeNode* root) {
        return dfs(root, root -> val, root -> val);
    }
};