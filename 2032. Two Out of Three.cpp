class Solution {
public:
    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        int arr1[101] = {}, arr2[101] = {}, arr3[101] = {};

        for(int i : nums1) arr1[i] = 1;
        for(int i : nums2) arr2[i] = 1;
        for(int i : nums3) arr3[i] = 1;

        vector<int> ans;
        for(int i = 0; i < 101; i++)
            if(arr1[i] + arr2[i] + arr3[i] >= 2) ans.push_back(i);

        return ans;

    }
};