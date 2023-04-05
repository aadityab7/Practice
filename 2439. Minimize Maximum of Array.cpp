class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long sum = nums[0];
        int res = nums[0], avg;

        for(int i = 1; i < nums.size(); i++){
            sum += nums[i];
            avg = ceil((double) sum / (i + 1));
            res = max(res, avg);
        }

        return res;
    }
};