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
    void dfs(TreeNode *node, vector<int> & arr){
        if(!node) return;

        dfs(node -> left, arr);

        arr.push_back(node -> val);

        dfs(node -> right, arr);
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b, ans;

        dfs(root1, a);
        dfs(root2, b);

        int i = 0, j = 0;

        while(i < a.size() && j < b.size()){
            if(a[i] < b[j]) ans.push_back(a[i++]);
            else ans.push_back(b[j++]);
        }

        while(i < a.size()) ans.push_back(a[i++]);

        while(j < b.size()) ans.push_back(b[j++]);

        return ans;
    }
};

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
    void create_stack(stack<TreeNode*> &st, TreeNode *node){
        while(node != NULL){
            st.push(node);
            node = node -> left;
        }
    }

public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode *> s1, s2;
        vector<int> res;

        create_stack(s1, root1);
        create_stack(s2, root2);

        while(!s1.empty() && !s2.empty()){
            
            if(s1.top()->val < s2.top()->val){
                TreeNode *x = s1.top();
                res.push_back(x -> val);
                s1.pop();
                create_stack(s1, x -> right);
            }
            else{
                TreeNode *x = s2.top();
                res.push_back(x -> val);
                s2.pop();
                create_stack(s2, x -> right);
            }

        }

        while(!s1.empty()){
            TreeNode *x = s1.top();
            res.push_back(x->val);
            s1.pop();
            create_stack(s1, x -> right);
        }

        while(!s2.empty()){
            TreeNode *x = s2.top();
            res.push_back(x->val);
            s2.pop();
            create_stack(s2, x -> right);
        }

        return res;
    }
};