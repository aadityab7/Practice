class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> st;
        // int arr[10001] = {};
        for(int i = 0; i < nums.size(); i++){
            if(st.find(nums[i]) != st.end()) return nums[i];
            st.insert(nums[i]);
        }
        
        return 0;
    }
};