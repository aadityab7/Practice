class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int j = 0;
        int temp;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i]){
                //swap
                temp = nums[j];
                nums[j] = nums[i];
                nums[i] = temp;
                j++;
            }
        }
    }
};

// class Solution {
// public:
//     void moveZeroes(vector<int>& nums) {
        
//         int j = 0;
        
//         for(int i = 0; i < nums.size(); i++){
//             if(nums[i] != 0){
//                 nums[j] = nums[i];
//                 j++;
//             }
//         }
        
//         for(; j < nums.size(); j++){
//             nums[j] = 0;
//         }
        
//     }
// };