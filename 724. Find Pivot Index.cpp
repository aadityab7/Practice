class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //if sum[i - 1] == sum[i + 1] - sum[i]
        //sum = total - sum;
        int total = 0;
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++) total+=nums[i];
        
        for(int i = 0; i < nums.size(); i++){
            if(sum == total - nums[i]) return i;
            
            sum += nums[i];
            total -= nums[i];
        }
        
        return -1;
    }
};

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //if sum[i - 1] == sum[i + 1] - sum[i]
        //sum = total - sum;
        int total = 0, sum = 0;
        
        for(int i = 0; i < nums.size(); i++) total+=nums[i];
        
        for(int i = 0; i < nums.size(); i++){
            if(sum == total - sum - nums[i]) return i;
            sum += nums[i];
        }
        
        return -1;
    }
};


//USING FOR EACH LOOP
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        //if sum[i - 1] == sum[i + 1] - sum[i]
        //sum = total - sum;
        int total = 0, sum = 0;
        
        for(auto x : nums) total += x;
        
        for(int i = 0; i < nums.size(); i++){
            if(sum == total - sum - nums[i]) return i;
            sum += nums[i];
        }
        
        return -1;
    }
};