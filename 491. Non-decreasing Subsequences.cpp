//backtracking
class Solution {
    vector<int> curr;

    void helper(int index, vector<int> &nums, set<vector<int>> &ans){
        if(curr.size() >= 2){
            ans.insert(curr);
        }

        if(index == nums.size()) return;

        helper(index + 1, nums, ans);

        if(curr.size() == 0 || curr.back() <= nums[index]){
            curr.push_back(nums[index]);

            helper(index + 1, nums, ans);

            curr.pop_back();
        }  
    }
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> ans;
        helper(0, nums, ans);

        vector<vector<int>> res;
        for(auto itr = ans.begin(); itr != ans.end(); itr++){
            res.push_back(*itr);
        }

        return res;
    }
};