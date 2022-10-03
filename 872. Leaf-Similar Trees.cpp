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
private:
    vector<int> a, b;
    
    void pre(TreeNode * node, int flag){
        if(!node) return;
        
        if(!(node -> left) && !(node -> right)){
            if(flag) a.push_back(node -> val);    
            else b.push_back(node -> val);
        }
            
        pre(node -> left, flag);
        pre(node -> right, flag);
    }
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        pre(root1, 1);
        pre(root2, 0);
        
        if(a.size() != b.size()) return false;
        
        for(int i = 0; i < a.size(); i++){
            //cout << a[i] << ' ' << b[i] << '\n';
            if(a[i] != b[i]) return false;
        }
        
        return true;
    }
};

//Smaller
class Solution {
private:
    void pre(TreeNode * node, vector<int> &arr){
        if(!node) return;
        
        if(!(node -> left) && !(node -> right)) arr.push_back(node -> val);
        pre(node -> left, arr);
        pre(node -> right, arr);
    }
    
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> a, b;
        
        pre(root1, a);
        pre(root2, b);
        
        return a == b;
    }
};