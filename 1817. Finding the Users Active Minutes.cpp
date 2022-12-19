//806 ms
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> mp;

        for(vector<int> log : logs) mp[log[0]].insert(log[1]);
    
        vector<int> ans(k , 0);

        int x;

        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            x = itr -> second.size();
            if(x <= k) ans[x - 1]++;
        }

        return ans;
    }
};

//for each loops run much faster when we use reference (&) instead of normal for each 
//264 ms
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        vector<int> ans(k , 0);
        unordered_map<int, unordered_set<int>> mp;

        // for(vector<int> log : logs) mp[log[0]].insert(log[1]);

        for(vector<int>& log : logs) mp[log[0]].insert(log[1]);
        
        int x;

        // for(auto itr = mp.begin(); itr != mp.end(); itr++){
        //     x = itr -> second.size();
        //     if(x <= k) ans[x - 1]++;
        // }

        for(auto &[user, time] : mp){
            if(time.size() <= k) ans[time.size() - 1]++;
        }

        return ans;
    }
};


class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        set<pair<int, int>> st;

        for(vector<int> log : logs) st.insert({log[0], log[1]});

        unordered_map<int, int> mp;

        for(auto itr = st.begin(); itr != st.end(); itr++)
            mp[itr -> first]++;

        vector<int> ans(k, 0);

        for(auto itr = mp.begin(); itr != mp.end(); itr++)
            if(itr -> second <= k) ans[itr -> second - 1]++;

        return ans; 
    }
};