class Solution {
    vector<vector<int>> ans;
    vector<int> curr;

    void helper(int x, int nums, int sum){
        if(sum < 0 || nums < 0) return;
        else if(nums == 0 && sum == 0){
            ans.push_back(curr);
            return;
        }
        
        for(int i = x + 1; i < 10; i++){
            curr.push_back(i);
            helper(i, nums - 1, sum - i);
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum3(int k, int n) {
        helper(0, k, n);
        return ans;
    }
};