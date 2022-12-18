//176 ms
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
    int index = 0;

    //root left right
    TreeNode* helper(int level, string s){
        //read number of dashes
        int count = 0;
        int i = index;
        while(i < s.size() && s[i] == '-'){
            count++;
            i++;
        }
        //if number of dashes == level
        //read the number and update index and create a node  
        //else return null

        if(count < level) return NULL;
        
        int num = 0;
        while(i < s.size() && s[i] != '-'){
            num *= 10;
            num += s[i] - '0';
            i++;
        }

        if(num == 0) return NULL;

        TreeNode *node = new TreeNode(num);

        index = i;

        node -> left = helper(level + 1, s);

        node -> right = helper(level + 1, s);

        return node;
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        return helper(0, traversal);
    }
};

//Condensed Version - 21 ms
class Solution {
    int index = 0;
    string s;

    TreeNode* helper(int level){
        int i = index;
        while(i < s.size() && s[i] == '-') i++;

        if(i - index < level) return NULL;
        
        int num = 0;
        while(i < s.size() && s[i] != '-'){
            num *= 10;
            num += s[i++] - '0';
        }

        if(num == 0) return NULL;

        TreeNode *node = new TreeNode(num);

        index = i;

        node -> left = helper(level + 1);
        node -> right = helper(level + 1);

        return node;
    }
public:
    TreeNode* recoverFromPreorder(string traversal) {
        s = traversal;
        return helper(0);
    }
};