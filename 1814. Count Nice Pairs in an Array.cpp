class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        int ans = 0, n = nums.size();
        int MOD = 1e9 + 7;
        
        unordered_map<int, long> mp;

        for(int i = 0; i < n; i++){
            int temp = nums[i], rev = 0;

            while(temp){
                rev *= 10;
                rev += temp % 10;
                temp /= 10;
            }
            
            mp[nums[i] - rev]++;
        }

        for(auto [diff, count] : mp){
            long x = count * (count - 1) / 2;
            ans = (ans + x) % MOD;
        }

        return ans;
    }
};