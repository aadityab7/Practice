class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int inc = 1, dec = 1;
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] == nums[i - 1]) continue;
            
            if(nums[i] < nums[i - 1]) inc = 0;
            else dec = 0;
        }
        
        return inc || dec;
    }
};