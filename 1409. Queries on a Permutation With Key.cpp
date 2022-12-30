class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> ans;
        unordered_map<int, int> mp;
        for(int i = 1; i <= m; i++) mp[i] = i - 1;
        int curr;

        for(int q : queries){
            curr = mp[q];
            ans.push_back(curr);

            for(auto itr = mp.begin(); itr != mp.end(); itr++)
                if(itr -> second < curr) itr -> second++;
            
            mp[q] = 0;
        }

        return ans;
    }
};