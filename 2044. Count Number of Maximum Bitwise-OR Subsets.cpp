//Backtracking - 34 ms
class Solution {
    int ans = 0, mx = 0;

    void helper(vector<int>& nums, int index, int o){
        o |= nums[index];
        
        if(o > mx){ 
            mx = o;
            ans = 1;
        }
        else if(o == mx) ans++;

        for(int i = index + 1; i < nums.size(); i++)
            helper(nums, i, o);
        
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++) helper(nums, i, 0);
        
        return ans;
    }
};

//19 ms
class Solution {
    int ans = 0, target = 0;

    void helper(vector<int>& nums, int index, int o, int target){
        o |= nums[index];
        
        if(o == target) ans++;

        for(int i = index + 1; i < nums.size(); i++) helper(nums, i, o, target);
    }

public:
    int countMaxOrSubsets(vector<int>& nums) {
        //maximum OR will be of all elements in array 
        for(int n : nums) target |= n;

        for(int i = 0; i < nums.size(); i++) helper(nums, i, 0, target);
        
        return ans;
    }
};