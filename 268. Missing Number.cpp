class Solution {
public:
    int missingNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != i){
                return i;
            }
        }
        
        return nums.size();
    }
};

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        long total = 0, sum = 0;
        sum = (nums.size() * (nums.size() + 1)) / 2;
        
        for(int i = 0; i < nums.size(); i++){
           total += nums[i];
        }
        
        return sum - total;
    }
};