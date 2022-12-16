class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans(nums.size());

        for(int i = 0; i < nums.size(); i++){
            ans[i] = nums[nums[i]];
        }

        return ans;
    }
};

class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        vector<int> ans;

        for(int x : nums) ans.push_back(nums[x]);

        return ans;
    }
};

//IN PLACE
//by maintaining the position and value both in same arr
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size(), pos, val;

        for(int i = 0; i < n; i++){
            pos = nums[i];
            val = nums[nums[i]] % n;
            nums[i] = n * val + pos;
        }

        for(int i = 0; i < n; i++) nums[i] = nums[i] / n;  

        return nums;
    }
};