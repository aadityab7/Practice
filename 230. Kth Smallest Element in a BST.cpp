//It is a binary tree so the kth element in traversal is the answer (BST is sorted)
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
    

    void dfs(TreeNode *node, vector<int> &arr){
        if(!node) return;

        dfs(node -> left, arr);
        arr.push_back(node -> val);
        dfs(node -> right, arr);
    }

public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;
        dfs(root, arr);
        return arr[k - 1];
    }
};

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        priority_queue<int> pq;

        queue<TreeNode *> q;
        q.push(root);

        TreeNode *temp;

        while(!q.empty()){
            temp = q.front();
            q.pop();    

            if(pq.size() < k) pq.push(temp -> val);
            else if(pq.top() > temp -> val){
                pq.pop();
                pq.push(temp -> val);
            } 

            if(temp -> left) q.push(temp -> left);
            if(temp -> right) q.push(temp -> right);
        }

        return pq.top();
    }
};