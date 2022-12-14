class Solution {
public:
    int rob(vector<int>& nums) {
        int mx = 0;

        //make most profit
        for(int i = 0; i < nums.size(); i++){
            //you can rob this house after robbing i - 2 house
            //or i - 3 house
            if(i > 2) nums[i] += max(nums[i - 2], nums[i - 3]);
            else if(i > 1) nums[i] += nums[i - 2];

            if(nums[i] > mx) mx = nums[i];
        }

        return mx;

    }
};
class Solution {
public:
    int rob(vector<int>& nums) {
        int mx = 0;
        //make most profit
        for(int i = 0; i < nums.size(); i++){
            //you can rob this house after robbing i - 2 house
            //or i - 3 house
            if(i > 2) nums[i] += max(nums[i - 2], nums[i - 3]);
            else if(i > 1) nums[i] += nums[i - 2];
        }

        mx = nums[nums.size() - 1];
        if(nums.size() > 1 && nums[nums.size() - 2] > mx) mx = nums[nums.size() - 2];

        return mx;

    }
};