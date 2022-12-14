//25 ms
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int ans = 0;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] <= nums[i - 1]){
                //make it nums[i - 1]+ 1
                ans += nums[i - 1] + 1 - nums[i];
                nums[i] = nums[i - 1] + 1;
            }
        }

        return ans;

    }
};

//14 ms
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int curr = nums[0] + 1;
        int ans = 0;

        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < curr){
                ans += curr - nums[i];

                nums[i] = curr;
            }

            curr = nums[i] + 1;
        }

        return ans;

    }
};

