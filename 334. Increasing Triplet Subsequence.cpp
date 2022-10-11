class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> mn(n);
        vector<int> mx(n);
        
        int min = nums[0], max = nums[n - 1];
        
        for(int i = 0; i < n; i++){
            if(nums[i] < min) min = nums[i];
            if(nums[n - i - 1] > max) max = nums[n - i - 1];
            
            mn[i] = min;
            mx[n - i - 1] = max;
        }
        
        for(int i = 0; i < n; i++){
            if(nums[i] != mn[i] && nums[i] != mx[i]) return true;
        }
        
        return false;
        
    }
};

//98 99 100 7 8
//5 100 6 4 8 

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int min = INT_MAX, min2 = INT_MAX;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < min){
                min = nums[i];
            }
            else if(nums[i] > min && nums[i] < min2){
                min2 = nums[i];
            }
            else if(nums[i] > min2) return true;
        }
        
        return false;
        
    }
};

//3 4 2 100 5
//1 10 5 20
//98 99 100 7 8
//5 100 6 4 8 
//8 7 100 5 