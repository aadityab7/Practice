class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> ans(nums.size());
        int o = 1, e = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] % 2) {
                ans[o] = nums[i];
                o+=2;
            }
            else{
                ans[e] = nums[i];
                e+=2;
            }
        }
        
        return ans;
    }
};

//In Place and faster
class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        int i = 0, j = 1;
        
        //traverse all the even indexes and if there is a odd number there switch it with an even number on the odd index
        
        while(i < nums.size() && j < nums.size()){
            //i only goes to even indices
            //j only goes to odd indices 
            
            if(nums[j] % 2 == 0 && nums[i] % 2 == 1){
                //swap 
                int t = nums[i];
                nums[i] = nums[j];
                nums[j] = t;
            }
            
            if(nums[i] % 2 == 0) i+=2;
            if(nums[j] % 2 == 1) j+=2;
        }
        
        return nums;
    }
};