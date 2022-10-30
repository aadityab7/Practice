class Solution {
    void swap(vector<int> &nums, int x, int y){
        int temp = nums[x];
        nums[x] = nums[y];
        nums[y] = temp;
    }
    
    void reverse(vector<int> &nums, int start){
        int i = start;
        int j = nums.size() - 1;
        
        while(i < j){
            swap(nums, i, j);
            i++;
            j--;
        }
    }
    
public:
    void nextPermutation(vector<int>& nums) {
        //find the element suvh that nums[i] < nums[i + 1]
        int i = nums.size() - 2;
        while(i >= 0 && nums[i] >= nums[i + 1]){
            i--;
        }
        
        //now either all elements are descending 
        //or we found a dip
        if(i >= 0){
            //now find the element just bigger than nums[i] after i 
            //swap them 
            int j = nums.size() - 1;
            while(j > i && nums[j] <= nums[i]){
                j--;
            }
            swap(nums, i, j);
        }
        
        
        //to get the next smallest perm reverse all the elements after i
        //arrange them in accending order
        reverse(nums, i + 1);
        
    }
};
