class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        //for each circle calc the euclidian dist of points from center
        vector<int> ans(queries.size(), 0);
        int curr, xx, yy, x, y, r, i, j;

        for(i = 0; i < queries.size(); i++){
            x = queries[i][0];
            y = queries[i][1];
            r = queries[i][2];
            for(j = 0; j < points.size(); j++){
                //if dist from center less than radius then inside and curr++
                xx = (x - points[j][0]);
                yy = (y - points[j][1]);

                if((r * r) >= ((xx * xx) + (yy * yy))) ans[i]++;
            }
        }

        return ans;
    }
};