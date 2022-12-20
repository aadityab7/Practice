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

    //contains all posible FBT for n - so that we don't have to repetedly perform recursion
    map<int, vector<TreeNode*>> mp;

    //making a deep copy
    TreeNode* clone(TreeNode *node){
        TreeNode* res = new TreeNode(0);

        if(node->left) res->left = clone(node->left);
        if(node->right) res->right = clone(node->right);

        return res;
    }

public:
    vector<TreeNode*> allPossibleFBT(int n) {
        //cout << n << '\n';

        //if we don't already have the result in map
        if(mp.find(n) == mp.end()){
            
            vector<TreeNode*> ans;

            if(n == 1){
                TreeNode* node = new TreeNode(0);
                ans.push_back(node);
            }
            else if(n % 2 == 1){
                //runs only for odd n

                for(int i = 1; i < n; i += 2){
                    
                    int j = n - 1 - i;

                    for(TreeNode* x : allPossibleFBT(i)){
                        for(TreeNode* y : allPossibleFBT(j)){
                            TreeNode* node = new TreeNode(0);

                            node->left = clone(x);
                            node->right = clone(y);

                            ans.push_back(node);
                        }
                    }
                }

            }//end of if - else if 

            mp[n] = ans;
        }
        
        return mp[n];
    }
};


/*
Things to note : FBT for even n does not exist
and the base case is n = 1
*/