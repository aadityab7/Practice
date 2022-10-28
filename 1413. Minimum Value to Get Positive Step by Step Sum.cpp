class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int min = nums[0];
        int sum = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sum += nums[i];
            if(sum < min) min = sum;
        }
        
        int ans = 1;
        
        if(min < 0) ans = 1 - min;
        
        return ans;
    }
};

//10 20 3 -10 -20
//33 - 30 = 3
//-30