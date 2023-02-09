class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        vector<set<string>> groups(26);
        long long ans = 0;
        int mutuals = 0;
        
        for(string idea : ideas) groups[idea[0] - 'a'].insert(idea.substr(1));

        for(int i = 0; i < 25; i++){
            for(int j = i + 1; j < 26; j++){
                mutuals = 0;

                for(string itr : groups[i])
                    mutuals += groups[j].count(itr);

                ans += 2 * (groups[i].size() - mutuals) * (groups[j].size() - mutuals);
            }   
        }

        return ans;
    }
};