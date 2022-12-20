class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int n = nums.size(), ans = 0;

        for(int i = 0; i < n / 2; i++)
            ans = max(ans, nums[i] + nums[n - i - 1]);
        
        return ans;
    }
};

//using a fixed size array to represent sorted numbers
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int arr[100001] = {};
        for(int &i : nums) arr[i]++;

        int i = 0, j = 100000;
        int ans = 0;

        while(i < j){
            while(i < j && arr[i] == 0) i++;
            while(i < j && arr[j] == 0) j--;

            if(arr[i] && arr[j]){
                if(i + j > ans) ans = i + j;
                arr[i]--;
                arr[j]--;
            }
        }

        return ans;
    }
};