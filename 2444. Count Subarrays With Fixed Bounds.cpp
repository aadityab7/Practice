class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int lastbad = -1, lastmin = -1, lastmax = -1;

        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > maxK || nums[i] < minK) lastbad = i;
            else{
                if(nums[i] == maxK) lastmax = i;
                if(nums[i] == minK) lastmin = i;
            }
            
            ans += max(0, min(lastmin, lastmax) - lastbad);
        }

        return ans;
    }
};