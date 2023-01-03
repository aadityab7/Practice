//66 ms

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> temp = nums;
        sort(nums.begin(), nums.end());

        int l = 0, r = nums.size() - 1; 

        while(l < nums.size() && temp[l] == nums[l]) l++;

        while(r >= 0 && temp[r] == nums[r]) r--;

        if(r >= l) return r - l + 1;

        return 0;
    }
};

//find the first and last elements which are in place


//19 ms
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int mn = INT_MAX, mx = INT_MIN;
        int flag = 0, flag2 = 0;
        int n = nums.size();

        for(int i = 1; i < n; i++){
            if(nums[i] < nums[i - 1]) flag = 1;

            if(flag) mn = min(mn, nums[i]); 

            if(nums[n - i - 1] > nums[n - i]) flag2 = 1;

            if(flag2) mx = max(mx, nums[n - i - 1]);
        }

        //now we have min and max elements of unsorted array 

        //find there correct position
        int l = 0, r = 0;
        flag = 1; flag2 = 1;

        for(int i = 0; i < n; i++){
            if(flag && mn < nums[i]){
                l = i;
                flag = 0;
            }

            if(flag2 && mx > nums[n - i - 1]){
                r = n - i - 1;
                flag2 = 0;
            }
        }

        if(r > l) return r - l + 1;

        return 0;
    }
};

//find the first and last elements which are in place

/*
9 10 11 1 2 3 13 14 15
*/