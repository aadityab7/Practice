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
    vector<string> ans;
    
    void paths(TreeNode * node, string s){
        if(!node) return;
        
        if(node -> left == NULL && node -> right == NULL){
            //leaf node
            ans.push_back(s);
        }
        
        //root left right
        if(node -> left){
            string l = s + "->" + to_string(node -> left -> val);
            paths(node -> left, l);
        }
        
        if(node -> right){
            string r = s + "->" + to_string(node -> right -> val);
            paths(node -> right, r);
        }
        
    }
    
    vector<string> binaryTreePaths(TreeNode* root) {
        if(!root) return ans;
        paths(root, to_string(root -> val));
        return ans;
        //level order traversal 
//         vector<string> ans;
//         if(!root) return ans;
        
//         queue<pair<TreeNode *, string>> q;
        
//         q.push({root, to_string(root -> val)});
        
//         while(!q.empty()){
//             TreeNode * node = q.front().first;
            
//             string s = q.front().second;
//             q.pop();
            
//             if(temp -> right == NULL && temp -> left == NULL){
//                 ans.push_back(s);
//             }
            
//             if(temp -> left){
//                 string t =  s + "->" + to_string(temp -> left -> val);
//                 q.push({temp -> left, t});
//             }
            
//             if(temp -> right){
//                 string t =  s + "->" + to_string(temp -> right -> val);
//                 q.push({temp -> left, t});
//             }
//         }
        
//         return ans;
    }
};


c/**
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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root) return ans; 
        queue<pair<TreeNode *, string>> q;
        q.push({root, to_string(root -> val)});
        string t, s;
        while(!q.empty()){
            TreeNode * node = q.front().first;
            s = q.front().second;
            q.pop();
            
            if((node -> left == NULL) && (node -> right == NULL)){
                ans.push_back(s);
            }
            if(node -> left){
                q.push({node -> left, (s + "->" + to_string(node -> left -> val))});
            }
            if(node -> right){
                q.push({node -> right, (s + "->" + to_string(node -> right -> val)) });
            }
        }
        return ans;
    }
};