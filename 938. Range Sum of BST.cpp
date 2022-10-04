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
    int l, h;
    int inorder_sum(TreeNode * node){
        if(!node) return 0;
        int x = 0, y = 0, z = 0;
        
        if(node -> val > l)
            x = inorder_sum(node -> left);
        
        if(node -> val >= l && node -> val <= h) 
            y = node -> val;
        
        if(node -> val < h)
            z = inorder_sum(node -> right);
        
        return x + y + z;
    } 
    
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        l = low;
        h = high;
        return inorder_sum(root);
    }
};

//DOING PREORDER TRAVERSAL TAKES ADVANTAGE OF THE FACT THAT TREE IS BST
//IF NODE > L ONLY THEN GO LEFT
//IF NODE < H ONLY THEN GO RIGHT
//FYI I CAME UP WITH THIS
class Solution {
private:
    int l, h;
    //node left right
    int pre(TreeNode * node){
        if(!node) return 0;
        int x = 0, y = 0, z = 0;
        
        if(node -> val >= l && node -> val <= h) 
            x = node -> val;
        
        if(node -> val > l)
            y = pre(node -> left);
        
        if(node -> val < h)
            z = pre(node -> right);
        
        return x + y + z;
    } 
    
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        l = low;
        h = high;
        return pre(root);
    }
};

//MINI
class Solution {  
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(!root) return 0;
        
        int val = (root -> val >= low && root -> val <= high) ? root -> val : 0;
        
        if(root -> val > low) val += rangeSumBST(root -> left, low, high);
        
        if(root -> val < high) val += rangeSumBST(root -> right, low, high);
        
        //root -> left = root -> right = NULL;
        return val;
    }
};