class Solution {
public:
    int search(vector<int>& nums, int target) {
        //find rotation
        //by finding the smallest element's index
        
        int lo = 0, hi = nums.size() - 1;
        int mid;
        
        while(lo < hi){
            mid = (lo + hi) / 2;
            
            if(nums[mid] > nums[hi]) lo = mid + 1;
            else hi = mid;
        }
        
        int rot = lo;
        lo = 0;
        hi = nums.size() - 1;
        int rmid;
        
        //usual binary search
        while(lo <= hi){
            mid = (lo + hi) / 2;
            rmid = (mid + rot) % nums.size();
            
            if(nums[rmid] == target) return rmid;
            else if(nums[rmid] < target) lo = mid + 1;
            else hi = mid - 1;
        }
        
        return -1;
    }
};