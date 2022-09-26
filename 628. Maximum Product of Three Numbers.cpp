class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //find the 3 maximum and 3 minimum numbers
        
        sort(nums.begin(), nums.end());
        
        int n = nums.size();
        int ans = nums[0] * nums[1] * nums[n - 1];
        int two = nums[n - 1] * nums[n - 2] * nums[n - 3];
        
        if(two > ans){
            ans = two;
        }
        
        return ans;
    }
};

/*
if all numbers are positive then ans = multiply max 3 numbers
else if the abs(min) > max and also abs(min + 1) > max - 1

*/


class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        //find the 3 maximum and 3 minimum numbers
        // sort(nums.begin(), nums.end());
        
        int max1 = -INT_MAX, max2 = -INT_MAX, max3 = -INT_MAX;
        int min1 = INT_MAX, min2 = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max1){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(nums[i] > max2){
                max3 = max2;
                max2 = nums[i];
            }
            else if(nums[i] > max3){
                max3 = nums[i];
            }
            
            if(nums[i] < min1){
                min2 = min1;
                min1 = nums[i];
            }
            else if(nums[i] < min2){
                min2 = nums[i];
            }
        }
        
        int ans = max1 * max2 * max3;
        int two = max1 * min1 * min2;
        
        if(two > ans){
            ans = two;
        }
        
        return ans;
    }
};

/*
if all numbers are positive then ans = multiply max 3 numbers
else if the abs(min) > max and also abs(min + 1) > max - 1

*/