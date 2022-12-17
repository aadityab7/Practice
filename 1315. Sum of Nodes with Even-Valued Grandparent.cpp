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

    void dfs(TreeNode *node, int p, int gp){
        if(!node) return;
        
        dfs(node -> left, node -> val, p);
        dfs(node -> right, node -> val, p);
        
        if(gp % 2 == 0) ans+= node -> val;
    }

public:
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, -1, -1);
        return ans;
    }
};

class Solution {
    int ans = 0;

    void dfs(TreeNode *node, TreeNode *p, TreeNode *gp){
        if(!node) return;
        
        dfs(node -> left, node, p);
        dfs(node -> right, node, p);
        
        if(gp && gp->val % 2 == 0) ans+= node -> val;
    }

public:
    int sumEvenGrandparent(TreeNode* root) {
        dfs(root, NULL, NULL);
        return ans;
    }
};