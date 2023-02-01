class Solution {
public:
    int numOfPairs(vector<string>& nums, string target) {
        unordered_map<string, int> mp;
        for(string s : nums) mp[s]++;

        int n = target.size(), ans = 0, size;

        for(string s : nums){
            
            size = s.size();
            
            if(size <= n){
                //after removing string from back
                string x = target.substr(0, size), y = target.substr(size);

                if(x == s){
                    ans += mp[y];

                    if(x == y) ans--;
                }
            }

        }


        return ans;
    }
};