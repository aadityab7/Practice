//using bfs
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
    int deepestLeavesSum(TreeNode* root) {
        int ans = 0;

        queue<TreeNode *> q;
        q.push(root);

        while(!q.empty()){
            //size of this level
            int size = q.size();
            ans = 0;

            for(int i = 0; i < size; i++){
                TreeNode *t = q.front();
                q.pop();

                ans += t -> val;

                if(t -> left) q.push(t -> left);
                if(t -> right) q.push(t -> right);
            }
        }

        return ans; 
    }
};


//using dfs and levels
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
int level = 0, ans = 0;

void dfs(TreeNode *node, int l){
    if(!node) return;

    if(node -> left == NULL && node -> right == NULL){
        //leaf node;
        if(l > level){
            level = l;
            ans = node -> val;
        }
        else if(l == level){
            ans += node -> val;
        }

        return;
    }
    
    //or we can traverse further down
    dfs(node -> left, l + 1);
    dfs(node -> right, l + 1);
    
}

public:
    int deepestLeavesSum(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};