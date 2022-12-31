//using bitmap array - 314 ms
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int size = nums.size();

        vector<int> bitmap(maximumBit, 0);
        vector<int> ans(size);
        int pos = size - 1;

        //get the bit representation of numbers in nums
        for(int n : nums){
            int temp = n;
            int i = 0;

            int x = 0;
            int t = 1;

            while(temp){
                if(temp % 2) bitmap[i]++;
                temp /= 2;
                i++;
            }

            for(int j = 0; j < maximumBit; j++){
                if(bitmap[j] % 2 == 0) x += t;
                t *= 2;
            }

            ans[pos] = x;
            pos--;
        }

        return ans;
    }
};

//using int - 151 ms
class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xo = nums[0];
        int n = nums.size();
        vector<int> ans(n);
        int mx = (1 << maximumBit) - 1;

        for(int i = 1; i < n; i++) xo ^= nums[i];

        for(int i = 0; i < nums.size(); i++){
            ans[i] = mx ^ xo;
            xo ^= nums[n - i - 1];
        }

        return ans;
    }
};