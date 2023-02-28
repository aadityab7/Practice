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
    unordered_set<string> final_st;
    vector<TreeNode*> ans;
    unordered_set<string> available;

    string dfs(TreeNode* node){
        if(!node) return "-";

        string res = to_string(node -> val) + ' ' + dfs(node -> left) + ' ' + dfs(node -> right);
        
        //check if another duplicate tree is present - if not insert in available
        //if true check if it is not already in answer
        //if not insert it in ans

        //if duplicate avaialble
        if(available.count(res)){
            //if not already in ans
            if(!final_st.count(res)){
                final_st.insert(res);
                ans.push_back(node);
            }
        }
        else{
            available.insert(res);
        }

        return res;
    } 

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        dfs(root);
        return ans;
    }
};