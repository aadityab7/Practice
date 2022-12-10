//MEDIUM
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
    TreeNode *total;
    
    TreeNode* dfs(TreeNode *node){
        if(!node) return NULL;
        
        TreeNode * l = dfs(node -> left);
        TreeNode * r = dfs(node -> right);

        int x = node -> val;

        if(l) x += l -> val;
        if(r) x += r -> val;

        TreeNode *res = new TreeNode(x, l, r);

        return res;
    }

public:
    int maxProduct(TreeNode* root) {
        total = dfs(root);
        long ans = 0;

        //perform level order traversal;
        //width first
        queue<TreeNode *> q;
        q.push(root);

        queue<TreeNode *> s;
        s.push(total);

        long x = 0, y = total -> val;

        while(!q.empty()){
            //now we have to decide wheater to put 
            //node + right in x and sub it from y
            //or put node + left in x and sub it from y
            TreeNode *temp = q.front();
            q.pop();
            
            TreeNode *t = s.front();
            s.pop();

            //get l and r
            TreeNode *l = t -> left;
            TreeNode *r = t -> right;

            long ll = temp -> val;
            if(l) ll += l -> val;
            
            long rr = temp -> val;
            if(r) rr += r -> val;

            long rx = x + rr;
            long ry = y - rr;
            long res1 = rx * ry;

            long lx = x + ll;
            long ly = y - ll;
            long res2 = lx * ly;
            
            long res = res1;

            if(res2 > res1){
                //put node with left and move to right
                q.push(temp -> right);
                s.push(r);
                res = res2;
                x = lx;
                y = ly;
            }
            else{
                //put node with right and move to left
                q.push(temp -> left);
                s.push(l);
                x = rx;
                y = ry;
            }
            
            if(res > ans) ans = res;
            else break;
        }

        int mod = 1000000007;
        
        return ans % mod;
    }
};

/*
each node should have a total sum associated with it 
calc sum by dfs - left right root
*/


//more consise solution
//using two paas of whole tree
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
    long mx = 0, total = 0;

    int dfs(TreeNode *node){
        if(!node) return 0;
        int curr = node -> val + dfs(node -> right) + dfs(node -> left);
        if(curr * (total - curr) > mx) mx = curr * (total - curr);
        return curr;
    }

public:
    int maxProduct(TreeNode* root) {
        total = dfs(root);
        dfs(root);

        int mod = 1000000007; 
        return mx % mod;
    }
};

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
    long mx = 0, total = 0;

    int tot(TreeNode * node){
        if(!node) return 0;
        int curr = node -> val + tot(node -> right) + tot(node -> left);
        return curr;
    }

    int dfs(TreeNode *node){
        if(!node) return 0;
        int curr = node -> val + dfs(node -> right) + dfs(node -> left);
        if(curr * (total - curr) > mx) mx = curr * (total - curr);
        return curr;
    }

public:
    int maxProduct(TreeNode* root) {
        total = tot(root);
        dfs(root);

        int mod = 1000000007; 
        return mx % mod;
    }
};