class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int ans = nums[0], curr = nums[0], n = nums.size();

        for(int i = 1; i < n; i++){
            if(nums[i] > nums[i - 1]){
                curr += nums[i];
            }
            else{
                if(curr > ans) ans = curr;
                curr = nums[i];
            }
        }

        if(curr > ans) ans = curr;

        return ans;
    }
};