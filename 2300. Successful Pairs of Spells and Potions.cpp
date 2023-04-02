class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        vector<int> ans;

        long long x, req;
        
        for(int spell : spells){
            req = ceil(success / (double) spell);

            x = lower_bound(potions.begin(), potions.end(), req) - potions.begin();

            ans.push_back(potions.size() - x);
        }

        return ans;
    }
};