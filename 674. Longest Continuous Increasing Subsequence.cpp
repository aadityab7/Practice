class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int start = 0;
        int ans = 1;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i - 1]){
                if((i - start) > ans){
                    ans = i - start;
                }
                start = i;
            }
        }
        
        if(nums.size() - start > ans){
            ans = nums.size() - start;
        }
        
        return ans;
    }
};