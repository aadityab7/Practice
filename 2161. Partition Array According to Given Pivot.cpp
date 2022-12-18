//240 ms
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size());
        int j = 0;
        
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] < pivot) ans[j++] = nums[i];
        }

        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == pivot) ans[j++] = nums[i];

        for(int i = 0; i < nums.size(); i++)
            if(nums[i] > pivot) ans[j++] = nums[i];

        return ans;
    }
};

//217 ms - best solution
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> eq, sm, gr;
        for(int x : nums){
            if(x == pivot) eq.push_back(x);
            else if(x > pivot) gr.push_back(x);
            else sm.push_back(x);
        }
  
        nums.clear();
        
        nums.insert(nums.end(), sm.begin(), sm.end());
        nums.insert(nums.end(), eq.begin(), eq.end());
        nums.insert(nums.end(), gr.begin(), gr.end());

        return nums;
    }
};