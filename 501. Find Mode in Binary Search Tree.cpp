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
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        unordered_map<int, int> mp;
        
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode * node;
        
        while(!q.empty()){
            node = q.front();
            q.pop();
            
            mp[node -> val]++;
            
            if(node -> left) q.push(node -> left);
            if(node -> right) q.push(node -> right);
        }
        
        int max = 0;
        vector<int> empty;
        
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(itr -> second > max){
                max = itr -> second; 
                ans = empty;
                ans.push_back(itr -> first);
            }
            else if(itr -> second == max){
                ans.push_back(itr -> first);
            }
        }
        
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
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> ans;
        unordered_map<int, int> mp;
        
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode * node;
        
        while(!q.empty()){
            node = q.front();
            q.pop();
            
            mp[node -> val]++;
            
            if(node -> left) q.push(node -> left);
            if(node -> right) q.push(node -> right);
        }
        
        int max = 0;

        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(itr -> second > max) max = itr -> second;
        }
        
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(itr -> second == max) ans.push_back(itr -> first);
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<int> ans;
    int curr = 0, max = 0, pre = INT_MIN;
    
    void inorder(TreeNode * node){
        if(!node) return;
        
        inorder(node -> left);
        
        if(node -> val == pre){
            curr++;
        }
        else{
            curr = 1;
        }
        
        if(curr > max){
            max = curr;
            ans.clear();
            ans.push_back(node -> val);
        }
        else if(curr == max){
            ans.push_back(node -> val);
        }
        
        pre = node -> val;//1
        
        inorder(node -> right);
        
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return ans;    
    }
};