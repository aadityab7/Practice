class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int largest = 0, sec = INT_MIN;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > nums[largest]){
                sec = nums[largest];
                largest = i;
            }
            else if(nums[i] > sec && nums[i] < nums[largest]){
                sec = nums[i];
            }
        }
        
        return (nums[largest] >= (2 * sec)) ? largest : -1;
    }
};

class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int f = -1, s = -1, res = -1;
        
        for(int i = 0; i < nums.size(); i++){
            
            if(nums[i] >= f){
                s = f;
                f = nums[i];
                res = i;
            }
            else if(nums[i] > s){
                s = nums[i];
            }
            
        }
        
        return (f >= (2*s)) ? res : -1;
    }
};