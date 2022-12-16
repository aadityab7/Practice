class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int ans = nums[nums.size() - 1] - nums[0];

        for(int i = 0; i <= nums.size() - k; i++){
            if(nums[i + k - 1] - nums[i] < ans) ans = nums[i + k - 1] - nums[i];
        }

        return ans;
       
    }
};

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        int ans = INT_MAX, n = nums.size();

        for(int i = 0; i <= n - k; i++) 
            ans = min(ans, nums[i + k - 1] - nums[i]);
        
        return ans;
    }
};