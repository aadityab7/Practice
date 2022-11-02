class Solution {
public:
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int size = nums.size();
        
        if(nums[0] >= size) return size;
        
        for(int i = 1; i < size; i++){
            int x = size - i;
            
            if((nums[i - 1] < x) && (x <= nums[i])){
                return x;
            }
        }
        
        return -1;
    }
};
