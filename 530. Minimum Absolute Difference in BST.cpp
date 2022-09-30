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
    // int ans = INT_MAX;
    // TreeNode * prev = NULL;
    
    // void inorder(TreeNode *node){
    //     if(!node) return;
    
    //     if(node -> left)    inorder(node -> left);

    //     if(prev != NULL){
    //         ans = min(ans, (node -> val - prev -> val));
    //     }
        
    //     prev = node;
        
    //     if(node -> right)   inorder(node -> right);    
    // }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> arr;
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode * node = q.front();
            q.pop();
            
            arr.push_back(node -> val);
            
            if(node -> left) q.push(node -> left);
            if(node -> right) q.push(node -> right);
        }
        
       
        sort(arr.begin(), arr.end());
        
        int min = arr[1] - arr[0];
        for(int i = 1; i < arr.size(); i++){
            if(arr[i] - arr[i - 1] < min) min = arr[i] - arr[i - 1];
        }
        
        return min;
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
    int ans = INT_MAX;
    TreeNode * prev = NULL;
    
    void inorder(TreeNode *node){
        if(!node) return;
    
        if(node -> left)    inorder(node -> left);

        if(prev != NULL){
            ans = min(ans, (node -> val - prev -> val));
        }
        
        prev = node;
        
        if(node -> right)   inorder(node -> right);    
    }
    
    int getMinimumDifference(TreeNode* root) {
        inorder(root);
        return ans;
//         vector<int> arr;
        
//         queue<TreeNode *> q;
//         q.push(root);
        
//         while(!q.empty()){
//             TreeNode * node = q.front();
//             q.pop();
            
//             arr.push_back(node -> val);
            
//             if(node -> left) q.push(node -> left);
//             if(node -> right) q.push(node -> right);
//         }
        
       
//         sort(arr.begin(), arr.end());
        
//         int min = arr[1] - arr[0];
//         for(int i = 1; i < arr.size(); i++){
//             if(arr[i] - arr[i - 1] < min) min = arr[i] - arr[i - 1];
//         }
        
//         return min;
    }
};