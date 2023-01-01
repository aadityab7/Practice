//O(n) - 146 ms
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
    
        int sum = 0, total = 0, n = nums.size(), ans, i;

        for(i = 0; i < n; i++){
            sum += nums[i];
            total += i * nums[i];
        }

        ans = total;

        for(i = n - 1; i >= 0; i--){
            total = total + sum - n * nums[i];
            ans = max(ans, total);
        }

        return ans;
    }
};