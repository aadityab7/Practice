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
    bool ans = false;
    
    bool check(TreeNode * node, TreeNode * subNode){
        if(node == NULL && subNode == NULL) return true;
//         if(node == NULL || subNode == NULL) return false;
        
//         if(node -> val == subNode -> val){
//             return (check(node -> left, subNode -> left) && check(node -> right, subNode -> right));
//         } 
//         else{
//             return false;
//         }
        
        return(node && subNode && (node->val == subNode->val) && check(node -> left, subNode -> left) && check(node -> right, subNode -> right));
    }
    
    void isSub(TreeNode* node, TreeNode* subNode){
        if(!node) return;
        
        if(node -> val == subNode -> val){
            //if we found the node then ans = true;
            if(check(node, subNode)){
                ans = true;
            }
        }
    
        isSub(node -> left, subNode);
        isSub(node -> right, subNode);
    }
    
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        isSub(root, subRoot);
        return ans;
    }
};


//Little Shorter
class Solution {
private:
    bool check(TreeNode * node, TreeNode * subNode){
        if(node == NULL && subNode == NULL) return true;
        return(node && subNode && (node->val == subNode->val) && check(node -> left, subNode -> left) && check(node -> right, subNode -> right));
    }
    
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(!root) return false;
        
        if(root -> val == subRoot -> val){
            if(check(root, subRoot)){
                return true;
            }
        }
    
        return isSubtree(root -> left, subRoot) || isSubtree(root -> right, subRoot);
    }
};