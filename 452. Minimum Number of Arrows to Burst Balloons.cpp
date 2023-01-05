class Solution {
    static bool comp(pair<int, int> &a, pair<int, int> &b){
        return a.second < b.second;
    }

public:
    int findMinArrowShots(vector<vector<int>>& points) {
        vector<pair<int, int>> arr;

        for(auto p : points) arr.push_back({p[0], p[1]});

        sort(arr.begin(), arr.end(), comp);
        
        int ans = 1, curr = arr[0].second;

        for(auto &a : arr){
            if(a.first > curr){
                ans++;
                curr = a.second;
            }
        }

        return ans;
    }
};