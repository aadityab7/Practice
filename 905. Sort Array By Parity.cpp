class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        vector<int> ans(nums.size());
        int s = 0, l = nums.size() - 1;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2){ 
                ans[l] = nums[i];
                l--;
            }
            else{
                ans[s] = nums[i];
                s++;
            }
        }
        
        return ans;
    }
};

//IN-PLACE
class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int i = 0, j = nums.size() - 1;
        
        while(i < j){
            if(nums[i] % 2 > nums[j] % 2){
                //swap them if we have odd number before even
                int t = nums[j];
                nums[j] = nums[i];
                nums[i] = t;
            }
            
            if(nums[i] % 2 == 0) i++;
            if(nums[j] % 2 == 1) j--;
        }
        
        return nums;
    }
};