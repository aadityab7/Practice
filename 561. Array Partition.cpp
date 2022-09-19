class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int sum = 0;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < nums.size(); i += 2){
            sum += nums[i];
        }
        
        return sum;
    }
};

class Solution {
public:
    int max = 10000;
    
    int arrayPairSum(vector<int>& nums) {
        int arr[20001] = {};
        
        for(int i = 0; i < nums.size(); i++){
            arr[nums[i] + max]++;
        }
        
        int ans = 0;
        int isEven = 1;
        
        for(int i = 0; i <= 2 * max; i++){
            while(arr[i]){
                ans += (isEven ? (i - max) : 0);
                isEven = 1 - isEven;
                arr[i]--;
            }
        }
        
        return ans;
        
    }
};