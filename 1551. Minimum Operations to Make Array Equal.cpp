class Solution {
public:
    int minOperations(int n) {
        int ans = 0, i;

        for(i = 0; i < n / 2; i++) ans += n - 1 - 2 * i;
        
        return ans;
    }
};