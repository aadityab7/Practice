class Solution {
public:
    int maxProduct(vector<int>& nums) {
        //find two max values
        int max = 0, m = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > max){
                m = max;
                max = nums[i];
            }
            else if(nums[i] > m){
                m = nums[i];
            }
        }
        
        return (max - 1) * (m - 1);
    }
};