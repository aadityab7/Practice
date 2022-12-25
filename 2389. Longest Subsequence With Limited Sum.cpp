class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;

        sort(nums.begin(), nums.end());

        for(int i = 1; i < nums.size(); i++)
            nums[i] += nums[i - 1];
          
        for(int c : queries)
            ans.push_back(lower_bound(nums.begin(), nums.end(), c + 1) - nums.begin());
        
        return ans;
    }
};