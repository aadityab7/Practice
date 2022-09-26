class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        long sum = 0, ans;
        int i = 0;
        int j = k;
        
        for(i = 0; i < k; i++){
            sum += nums[i];
        }
        
        i = 0;
        ans = sum;
        int n = nums.size();
        
        while(j < n){
            sum -= (nums[i] - nums[j]);
            
            if(sum > ans)   ans = sum;
               
            j++;
            i++;
        }
        
        return ((double)ans / k);
    }
};

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double sum = 0, ans;
        int i = 0;
        int j = k;
        
        for(i = 0; i < k; i++){
            sum += nums[i];
        }
        
        ans = sum;
        int n = nums.size();
        
        while(j < n){
            sum += (nums[j] - nums[j - k]);
            ans = max(ans, sum);
            j++;
        }
        
        return ans / k;
    }
};