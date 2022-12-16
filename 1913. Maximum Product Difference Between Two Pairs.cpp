class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int a = nums[n - 1];
        int b = nums[n - 2];
        int c = nums[0];
        int d = nums[1];

        return (a * b) - (c * d);
    }
};

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int min = INT_MAX, min2 = INT_MAX, max = INT_MIN, max2 = INT_MIN;

        for(int x : nums){
            if(x > max){
                max2 = max;
                max = x;
            }
            else if(x > max2) max2 = x;

            if(x < min){
                min2 = min;
                min = x;
            }
            else if(x < min2) min2 = x;
            
        }

        return (max * max2) - (min * min2);
    }
};