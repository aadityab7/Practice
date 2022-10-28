class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int size = nums.size();
        vector<int> ans(size);
        vector<int> arr(size, -1);
        
        int x;
        for(int i = 0; i < size; i++){
            x = index[i];
            
            for(int j = 0; j < size; j++){
                if(arr[j] >= x) arr[j]++;
            }
            
            arr[i] = x;
        }
        
        for(int i = 0; i < size; i++){
            ans[arr[i]] = nums[i];
        }
        
        return ans;
    }
};

//2 0 4 1 3    