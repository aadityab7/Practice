class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> mp;
        for(auto i : tasks) mp[i]++;
        
        int ans = 0;

        for(auto x : mp){
            if(x.second == 1) return -1;
            else ans += ceil(x.second / 3.0);
        }

        return ans;
    }
};