class NumArray {
public:
    // vector<int> arr;
    vector<int> leftSum;
    
    NumArray(vector<int>& nums) {
        // arr = nums;
        
        leftSum.push_back(0);
        int sumL = 0;
        
        for(int i = 0; i < nums.size(); i++){
            sumL += nums[i];
            leftSum.push_back(sumL);
        }
    }
    
    int sumRange(int left, int right) {
        // int ans = 0;
        // for(int i = left; i <= right; i++){
        //     ans += arr[i];
        // }
        
        //last element - left - 1 - (last elem - right)
        // int ans = leftSum[leftSum.size() - 1] - leftSum[left] - (leftSum[leftSum.size() - 1] - leftSum[right + 1]);
        int ans = leftSum[right + 1] - leftSum[left];
        
        return ans;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
    
    3 4
    0 -2 -2 1 -4 -2 -3
    -3 -1 -1 -4 1 -1 0
    -3
    -3 - 1 = -4
    
    1 1 1 *1 *1 1
    1 2 3 4 5 6
    
    6 - 3 = 3
    6 - 5 = 1
    2
    -3 - 1 = -4
    -3 + 2 = -1
    -4 - - 1
 */