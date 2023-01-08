class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int ans = 1;

        for(int i = 0; i < points.size(); i++){
            unordered_map<double, int> mp;

            for(int j = 0; j < points.size(); j++){
                //calculate the atan2 btw every 2 points
                if(i != j)
                    mp[atan2(points[j][1] - points[i][1], points[i][0] - points[j][0])]++;
            }

            for(auto [x, y] : mp) ans = max(ans, y + 1);
        }

        return ans;
    }
};