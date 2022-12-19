class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ltr(n), rtl(n), ans(n);

        ltr[0] = nums[0];
        rtl[n - 1] = nums[n - 1];

        for(int i = 1; i < n - 1; i++){
            ltr[i] = ltr[i - 1] * nums[i];

            rtl[n - i - 1] = rtl[n - i] * nums[n - i - 1];
        }

        ans[0] = rtl[1];
        ans[n - 1] = ltr[n - 2];

        for(int i = 1; i < n - 1; i++){
            ans[i] = rtl[i + 1] * ltr[i - 1];
        }

        return ans;
    }
};

//Using a single array
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n);

        int l = 1;
        for(int i = 0; i < n; i++){
            arr[i] = l;
            l *= nums[i];
        }

        int r = 1;
        for(int i = n - 1; i >= 0; i--){
            arr[i] *= r;
            r *= nums[i];
        }

        return arr;
    }
};