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
    TreeNode* reverseOddLevels(TreeNode* root) {
        int level = 0, flag = 1;
        int pos = 0;

        queue<TreeNode*> q;
        q.push(root);
        
        vector<int> temp;

        while(!q.empty()){
            int size = q.size();

            if(level % 2 && flag){
                temp.clear();

                for(int i = 0; i < size; i++){
                    TreeNode *node = q.front(); q.pop();

                    temp.push_back(node->val);
                    q.push(node);
                }
                
                pos = temp.size() - 1;
                flag = 0;
            }
            else{
                for(int i = 0; i < size; i++){
                    TreeNode * node = q.front(); q.pop();

                    if(level % 2){
                        node -> val = temp[pos--];
                    }
                    
                    if(node -> left) q.push(node -> left);
                    if(node -> right) q.push(node -> right);

                }

                level++;
                flag = 1;
            }
        }

        return root;
    }
};

/*

*/