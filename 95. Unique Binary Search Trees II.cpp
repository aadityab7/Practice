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
    
    vector<TreeNode*> create(int start, int end){
        vector<TreeNode*> res;
        
        if(start >= end){
            res.push_back(NULL);
            return res;
        }
        
        for(int i = start; i < end; i++){
            //start from 1 and go upto n 
            //for each i get the subtrees for i - 1 
            //and subtrees for i + 1
            
            vector<TreeNode*> l = create(start, i);
            vector<TreeNode*> r = create(i + 1, end);
            
            //all possible combinations of nodes
            for(int j = 0; j < l.size(); j++){
                for(int k = 0; k < r.size(); k++){
                    TreeNode * temp = new TreeNode(i);
                    temp -> left = l[j];
                    temp -> right = r[k];
                    res.push_back(temp);
                }
            }
            
        }
        
        return res;
        
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        return create(1, n + 1);
    }
};

/*
create all posible trees with start to end numbers 
with 1 as 1 and null as null
2
0 1
1 0

*/
* 
class Solution {
    
    vector<TreeNode*> create(int start, int end){
        
        vector<TreeNode*> res;
        
        if(start == end){
            res.push_back(NULL);
            return res;
        }
        
        int i, j, k;
        
        for(i = start; i < end; i++){
            //start from 1 and go upto n 
            //for each i get the subtrees for i - 1 
            //and subtrees for i + 1
            
            vector<TreeNode*> l = create(start, i);
            vector<TreeNode*> r = create(i + 1, end);
            
            //all possible combinations of nodes
            for(j = 0; j < l.size(); j++){
                for(k = 0; k < r.size(); k++){
                    TreeNode * temp = new TreeNode(i);
                    temp -> left = l[j];
                    temp -> right = r[k];
                    res.push_back(temp);
                }
            }
            
        }
        
        return res;
        
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        return create(1, n + 1);
    }
};