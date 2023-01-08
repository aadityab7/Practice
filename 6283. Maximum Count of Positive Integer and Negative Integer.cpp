class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg = 0, zero = 0;
        
        for(int &num : nums){
            if(num < 0) neg++;
            else if(num == 0) zero++;
            else break;
        }
        
        int pos = nums.size() - neg - zero;
        
        return max(pos, neg);
        
    }
};