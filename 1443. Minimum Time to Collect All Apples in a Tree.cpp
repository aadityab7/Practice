class Solution {
    unordered_map<int, vector<int>> mp;
    int ans = 0;

    bool helper(int index, int parent, const vector<bool>& hasApple){
        bool res = hasApple[index];

        for(int nieghbour : mp[index])
            if(nieghbour != parent) res |= helper(nieghbour, index, hasApple);
            
        if(res) ans++;

        return res;
    }
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for(auto e : edges){
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        
        for(int neighbour : mp[0]) helper(neighbour, 0, hasApple);

        return 2 * ans;
    }
};