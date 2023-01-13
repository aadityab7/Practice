//Using a map
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int ans = 0;

        for(int &x : nums){
            ans += mp[x + k] + mp[x - k];
            mp[x]++;
        }

        return ans;
    }
};

//using a array because range of nums is small
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int mp[101] = {}, ans = 0;

        for(int &x : nums){
            if(x - k >= 0) ans += mp[x - k];
            if(x + k < 101) ans += mp[x + k]; 
            mp[x]++;
        }

        return ans;
    }
};