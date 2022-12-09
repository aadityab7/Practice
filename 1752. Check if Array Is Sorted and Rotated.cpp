class Solution {
public:
    bool check(vector<int>& nums) {
        int flag = 0;
        
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i - 1]){
                //if it happens once its okay 
                //array is rotated at that point
                if(flag) return false;
                
                flag = 1;
            }
        }
        
        if(flag){
            //last element must be smaller than the first 
            //if array is rotated
            if(nums[0] < nums[nums.size() - 1]) return false;
        }
        
        return true;
    }
};

class Solution {
public:
    bool check(vector<int>& nums) {
        int flag = 0, n = nums.size();
        
        for(int i = 0; i < n; i++){
            if(nums[i] > nums[(i + 1) % n]){
                if(flag) return false;
                flag = 1;
            }
        }
        
        return true;
    }
};