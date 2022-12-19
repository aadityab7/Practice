class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int total = 0;
        for(int i : nums) total += i;

        int sum = 0;

        for(int i = 0; i < nums.size(); i++){
            if(sum == (total - sum - nums[i])) return i;
            sum += nums[i];
        }

        return -1;
    }
};