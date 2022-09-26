class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> ans(2);
        
        for(int i = 0; i < nums.size(); i++){
            if(st.find(nums[i]) != st.end()) ans[0] = nums[i];
            else st.insert(nums[i]);
        }
        
        for(int i = 1; i <= nums.size(); i++){
            if(st.find(i) == st.end()){
                ans[1] = i;
                break;
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> ans(2);
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[abs(nums[i]) - 1] < 0){
                //element already occured
                ans[0] = abs(nums[i]);
            }
            else{
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }
        }
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > 0){
                ans[1] = i + 1;
            }
        }
        
        return ans;
    }
};