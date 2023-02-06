class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> ans;
        int mid = nums.size() / 2;
        
        for(int i = 0; i < mid; i++){
            ans.push_back(nums[i]);
            ans.push_back(nums[i + mid]);
        }
        
        return ans;
    }
};