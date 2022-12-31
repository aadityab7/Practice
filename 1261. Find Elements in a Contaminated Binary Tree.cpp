//traversing the tree to search the number - 111 ms
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
class FindElements {
    TreeNode* r;

    void dfs(TreeNode* node, int v){
        node -> val = v;
        if(node -> left) dfs(node -> left, 2 * v + 1);
        if(node -> right) dfs(node -> right, 2 * v + 2);
    }

    bool b_find(TreeNode* node, int target){
        if(!node) return false;

        int v = node -> val;

        if(v == target) return true;
        else if(target > 2 * v) return b_find(node -> left, target) || b_find(node -> right, target);
        
        return false;
    }   

public:
    FindElements(TreeNode* root) {
        dfs(root, 0);    
        r = root;
    }
    
    bool find(int target) {
        //find the value in binary tree using binary search
        return b_find(r, target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */

//Storing values using set - 43 ms 
//using count() of set - 38 ms 
class FindElements {
    TreeNode* r;
    unordered_set<int> st;

    void dfs(TreeNode* node, int v){
        node -> val = v;
        st.insert(v);
        if(node -> left) dfs(node -> left, 2 * v + 1);
        if(node -> right) dfs(node -> right, 2 * v + 2);
    }

public:
    FindElements(TreeNode* root) {
        dfs(root, 0);    
        r = root;
    }
    
    bool find(int target) {
        //find the value in binary tree using binary search
        if(st.find(target) != st.end()) return true;
        return false;

        //or we can use count() - of set - 38 ms
        //return st.count(target);
    }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */