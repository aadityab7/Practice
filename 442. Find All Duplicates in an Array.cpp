class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;

        for(auto index = 0; index < nums.size(); index++){
            if(nums[abs(nums[index]) - 1] < 0) ans.push_back(abs(nums[index]));
            else nums[abs(nums[index]) - 1] *= -1;
        }

        return ans;
    }
};