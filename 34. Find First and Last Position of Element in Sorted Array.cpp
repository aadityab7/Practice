class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //use binary search to find the occurence of target in nums;
        int lo = 0;
        int hi = nums.size() - 1;
        
        vector<int> ans(2);
        ans[0] = -1;
        ans[1] = -1;
        
        int mid;
        
        while(lo <= hi){
            mid = (lo + hi) / 2;
            
            if(nums[mid] == target){
                //found it now find the range
                int i = mid;
                int j = mid;
                
                while(i >= 0 && nums[i] == target) i--;
                
                while(j < nums.size() && nums[j] == target) j++;
                
                i++;
                j--;
                
                ans[0] = i;
                ans[1] = j;
                
                break;
            }
            else if(nums[mid] > target){
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }
        
        return ans;
    }
};