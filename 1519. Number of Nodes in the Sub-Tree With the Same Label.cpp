//MY solution - 1617 ms
class Solution {
    unordered_map<int, vector<int>> mp;
    unordered_map<char, vector<int>> ch_mp;

   void helper(int index, int parent, string &labels, vector<int> &ans){
        //update all the indices that have the same letter
        ch_mp[labels[index]].push_back(index);

        for(int ind : ch_mp[labels[index]]) ans[ind]++;

        for(int neig : mp[index]){
            if(neig != parent) helper(neig, index, labels, ans);
        }

        ch_mp[labels[index]].pop_back();
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        for(auto e : edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }

        vector<int> ans(n, 0);
        helper(0, 0, labels, ans);

        return ans;
    }
};

//difference in count of label before and after visiting the subtree - 569 ms
class Solution {
    unordered_map<int, vector<int>> mp;

   void helper(int index, int parent, const string &labels, vector<int> &ans, vector<int> &count){
       //before visiting the subtree how many node with label were there
       //and how many new nodes have been found in subtree

        int before = count[labels[index] - 'a']++;

        for(int neig : mp[index])
            if(neig != parent) helper(neig, index, labels, ans, count);
        
        ans[index] = count[labels[index] - 'a'] - before;
    }

public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        for(auto e : edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }

        vector<int> count(26, 0);
        vector<int> ans(n, 0);
        helper(0, 0, labels, ans, count);

        return ans;
    }
};