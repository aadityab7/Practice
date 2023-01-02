class Solution {
    int ans = 0;

    void helper(int xo, int index, const vector<int> &nums){
        xo ^= nums[index];

        ans += xo;

        for(int i = index + 1; i < nums.size(); i++) helper(xo, i, nums);
    }

public:
    int subsetXORSum(vector<int>& nums) {
        int xo = 0;

        for(int i = 0; i < nums.size(); i++) helper(xo, i, nums);
        
        return ans;
    }
};