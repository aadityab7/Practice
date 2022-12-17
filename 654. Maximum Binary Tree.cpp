//299 ms
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

bool comp(pair<int, int> &a, pair<int, int> &b){
    return a.first < b.first;
}
class Solution {
    TreeNode* helper(vector<pair<int, int>> & arr){
        int n = arr.size();
        if(n == 0) return NULL;

        //max value as node 
        TreeNode *node = new TreeNode(arr[n - 1].first);
        int x = arr[n - 1].second;    

        vector<pair<int, int>> l, r;

        for(int i = 0; i < n - 1; i++){
            if(arr[i].second < x) l.push_back(arr[i]);
            else r.push_back(arr[i]);
        }

        node -> left = helper(l);
        node -> right = helper(r);

        return node;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr;

        for(int i = 0; i < n; i++){
            arr.push_back({nums[i], i});
        }

        sort(arr.begin(), arr.end(), comp);

        return helper(arr);
    }
};

//181 ms
//we can use a array of index only

bool comp(pair<int, int> &a, pair<int, int> &b){
    return a.first < b.first;
}

class Solution {
    vector<pair<int, int>> arr;

    TreeNode* helper(const vector<int> &nn, vector<int> &x){
        int n = x.size();
        if(n == 0) return NULL;

        TreeNode * node = new TreeNode(nn[x[n - 1]]);

        vector<int> l, r;
        for(int i = 0; i < n - 1; i++)
            if(x[i] < x[n - 1]) l.push_back(x[i]);
            else r.push_back(x[i]);


        node -> left = helper(nn, l);
        node -> right = helper(nn, r);
        return node;
    } 

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) arr.push_back({nums[i], i});
        
        sort(arr.begin(), arr.end(), comp);

        vector<int> x;
        for(int i = 0; i < n; i++) x.push_back(arr[i].second);

        return helper(nums, x);
    }
};