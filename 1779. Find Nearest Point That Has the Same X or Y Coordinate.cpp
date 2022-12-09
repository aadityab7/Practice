class Solution {
public:
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) {
        ios_base::sync_with_stdio(false); 
        cin.tie(0);
        cout.tie(0);

        int min = INT_MAX;
        int ans = -1;
        int curr;
        
        for(int i = 0; i < points.size(); i++){
            if(points[i][0] == x || points[i][1] == y){
                curr = abs(points[i][0] - x) + abs(points[i][1] - y);
                if(curr < min){
                    min = curr;
                    ans = i;
                } 
            }
        }

        return ans;

    }
};