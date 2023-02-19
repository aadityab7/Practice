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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        vector<vector<int>> ans;

        queue<TreeNode*> q;
        q.push(root);
        int depth = 0;

        while(!q.empty()){
            int size = q.size();
            vector<int> level(size);

            for(int i = 0; i < size; i++){
                TreeNode *node = q.front();
                q.pop();

                if(node -> left) q.push(node -> left);
                if(node -> right) q.push(node -> right);

                if(depth) level[size - i - 1] = node -> val;
                else level[i] = node -> val;
            }

            ans.push_back(level);

            depth = 1 - depth;
        }

        return ans;
    }
};