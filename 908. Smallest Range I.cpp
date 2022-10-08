class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        //find min and max and try
        int min = nums[0], max = nums[0];
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max) max = nums[i];
            if(nums[i] < min) min = nums[i];
        }
        
        int diff = max - min;
        //that is the curr diff we can reduce up to 2k from it
        int ans = diff - 2 * k;
        
        if(ans > 0) return ans;
        else return 0;
    }
}; 