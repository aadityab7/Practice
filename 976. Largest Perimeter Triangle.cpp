class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        //we need all sides to be smaller than the sum of other two
        //find triplets such that 
        //a <= b <= c
        //a + b > c;
        
        
        sort(nums.begin(), nums.end());
        
        for(int i = nums.size() - 3; i >= 0; i--){
           if(nums[i] + nums[i + 1] > nums[i + 2]) return nums[i] + nums[i+1] + nums[i+2];
        }
        
        return 0;
    }
    //100 49 49 
};