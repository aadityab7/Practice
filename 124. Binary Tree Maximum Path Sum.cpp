//HARD

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
int mx;

int dfs(TreeNode *node){
    int t = node -> val;
    
    int l = 0, r = 0;
    
    if(node -> left){
        l = dfs(node -> left);
    }

    if(node -> right){
        r = dfs(node -> right);
    }

    int ans = t;

    int x = t + l + r;
    int y = t + l;
    int z = t + r;

    if(y > ans) ans = y;
    if(z > ans) ans = z;

    if(x > mx) mx = x;
    if(ans > mx) mx = ans;

    return ans;
}

public:
    int maxPathSum(TreeNode* root) {
        mx = root -> val;
        dfs(root);

        return mx;
    }
};

//more consise
class Solution {
int mx;

int dfs(TreeNode *node){
    if(!node) return 0;

    int l = max(0, dfs(node -> left));
    int r = max(0, dfs(node -> right));
    int t = node -> val;

    mx = max(mx, t + l + r);
    return max(t + l, t + r);
}

public:
    int maxPathSum(TreeNode* root) {
        mx = root -> val;
        dfs(root);
        return mx;
    }
};