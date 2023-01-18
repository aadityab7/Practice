class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int normal_max = nums[0];
        int curr = 0;
        for(int i : nums){
            curr += i;
            normal_max = max(normal_max, curr);
            curr = max(curr, 0);
        } 

        //now calculate the suffix sum
        int n = nums.size();
        vector<int> suffix_sum(n);
        suffix_sum[n - 1] = nums[n - 1];

        curr = nums[n - 1];
        for(int i = n - 2; i >= 0; i--){
            curr += nums[i];
            suffix_sum[i] = max(curr, suffix_sum[i + 1]);
        }

        //now iterate through the array 
        curr = 0;
        int special_max = nums[0];
        for(int i = 0; i < n - 1; i++){
            curr += nums[i];
            special_max = max(special_max, curr + suffix_sum[i + 1]);
        }

        return max(special_max, normal_max);
    }
};