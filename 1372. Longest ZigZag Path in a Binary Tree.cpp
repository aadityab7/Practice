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
    void zig(TreeNode * node, int curr, bool left){
        if(!node){
            ans = max(ans, curr);
            return;
        }

        if(left){
            zig(node -> right, curr + 1, false);
            zig(node -> left, 0, true);
        }
        else{
            zig(node -> left, curr + 1, true);
            zig(node -> right, 0, false);
        }
    }
public:
    int longestZigZag(TreeNode* root) {
        zig(root -> left, 0, true);
        zig(root -> right, 0, false);
        return ans;
    }
};

//another one

class Solution {
    int ans = 0;

    int zig(TreeNode * node, bool left){
        if(!node) return -1;
        
        int l = 1 + zig(node -> left, false);
        int r = 1 + zig(node -> right, true);

        ans = max(ans, max(l, r));

        return left ? l : r;
    }
public:
    int longestZigZag(TreeNode* root) {
        zig(root, true);
        return ans;
    }
};