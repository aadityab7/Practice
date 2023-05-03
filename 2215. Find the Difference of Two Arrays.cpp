class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> arr(2, vector<int>(2500, 0));
        vector<vector<int>> ans(2, vector<int>());

        for(int i : nums1) arr[0][i + 1000] = 1;
        for(int i : nums2) arr[1][i + 1000] = 1;

        for(int i = 0; i < arr[0].size(); i++){
            if(arr[0][i] == 1 && arr[1][i] == 0) ans[0].push_back(i - 1000);
        }

        for(int i = 0; i < arr[1].size(); i++){
            if(arr[1][i] == 1 && arr[0][i] == 0) ans[1].push_back(i - 1000);
        }

        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;
        vector<vector<int>> ans(2, vector<int>());

        for(int i : nums1) s1.insert(i);
        for(int j : nums2) s2.insert(j);

        for(int x : s1){
            if(s2.count(x) == 0) ans[0].push_back(x);
        }

        for(int x : s2){
            if(s1.count(x) == 0) ans[1].push_back(x);
        }

        return ans;
    }
};