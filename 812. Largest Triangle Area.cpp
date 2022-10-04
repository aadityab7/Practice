class Solution {
public:
    double largestTriangleArea(vector<vector<int>>& points) {
        //find points a b c using brute force
        int n = points.size();
        double ans = 0, area = 0;
        
        for(int a = 0; a < n; a++){
            for(int b = a + 1; b < n; b++){
                for(int c = b + 1; c < n; c++){
                    //calc area using points a b c
                    //a = (x1, y1); b = (x2, y2); c = (x3, y3)
                    //area = x1 (y2 - y3) + x2 (y3 - y1) + x3 (y1 - y2);
                    double i = points[a][0] * (points[b][1] - points[c][1]);
                    double j = points[b][0] * (points[c][1] - points[a][1]);
                    double k = points[c][0] * (points[a][1] - points[b][1]);
                    area = abs(i + j + k);
                    area /= 2;
                    
                    if(area > ans) ans = area;
                }
            }
        }
        
        return ans;
    }
};