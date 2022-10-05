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
    bool isCousins(TreeNode* root, int x, int y) {
        //do level order traversal
        queue<pair<TreeNode * , TreeNode *>> q;
        q.push({root, NULL});
        TreeNode * px = NULL, * py = NULL;
        
        while(!q.empty()){
            int s = q.size();
            
            //traverse this level
            for(int i = 0; i < s; i++){
                TreeNode * node = q.front().first;
                TreeNode * p = q.front().second;
                q.pop();
                
                if(node -> val == x) px = p;
                else if(node -> val == y) py = p;
                
                if(node -> left) q.push({node -> left, node});
                if(node -> right) q.push({node -> right, node});
            }
            
            if(px == NULL && py == NULL) continue;
            
            //one found at this level and other not
            if(px == NULL || py == NULL) return false;
            
            //nodes x and y should have diff parents 
            if(px == py) return false;
            
            return true;
        }
        
        return true;
    }
};