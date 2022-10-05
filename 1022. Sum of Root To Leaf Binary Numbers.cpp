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
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        
        queue<pair<TreeNode *, string>> q;
        q.push({root, ""});
        
        while(!q.empty()){
            int s = q.size();
            
            for(int i = 0; i < s; i++){
                
                TreeNode * node = q.front().first;
                string x = q.front().second;
                q.pop();
                
                if(node -> val == 1) x += '1';
                else x += '0';
                
                if(node -> left == NULL && node -> right == NULL){
                    //cout << x << '\n';
                    //leaf node
                    //get int rep of x and add it to ans
                    int num = 0;
                    long bit = 1;
                    for(int j = x.size() - 1; j >= 0; j--){
                        if(x[j] == '1') num += bit;
                        bit *= 2;
                    }
                    
                    ans += num;
                }
                
                if(node -> left) q.push({node -> left, x});
                if(node -> right) q.push({node -> right, x});
                
            }
        }
        
        return ans;
        
    }
};


class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int ans = 0;
        
        queue<pair<TreeNode *, int>> q;
        q.push({root, 0});
        
        while(!q.empty()){
            int s = q.size();
            
            for(int i = 0; i < s; i++){
                
                TreeNode * node = q.front().first;
                int x = q.front().second;
                q.pop();
                
                x = (x << 1) | node->val;
                
                
                if(!node -> left && !node -> right) ans += x;
                
                if(node -> left) q.push({node -> left, x});
                if(node -> right) q.push({node -> right, x});
                
            }
        }
        
        return ans;
        
    }
};

//BEST SOLUTION
class Solution {
private:
    int pre(TreeNode * node, int num){
        if(!node) return 0;
        
        num = (num << 1) | node -> val;
        
        if(node -> left == NULL && node -> right == NULL) return num;
        
        return pre(node->left, num) + pre(node->right, num);
    }
    
public:
    int sumRootToLeaf(TreeNode* root) {
        return pre(root, 0);
    }
};