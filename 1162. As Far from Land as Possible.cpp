class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        long ans = 0, n = grid.size();
        vector<vector<long>> dist(n, vector<long>(n, INT_MAX));

        //first paas to check land before
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j]) dist[i][j] = 0;
                else{
                    long x = INT_MAX, y = INT_MAX;
                    if(i) y = dist[i - 1][j] + 1;
                    if(j) x = dist[i][j - 1] + 1;
                    
                    dist[i][j] = min(dist[i][j], min(x, y));
                }
            }
        }

        //second paas to check land after
        for(int i = n - 1; i >= 0; i--){
            for(int j = n - 1; j >= 0; j--){
                if(!grid[i][j]){
                    long x = INT_MAX, y = INT_MAX;
                    if(i < n - 1) y = dist[i + 1][j] + 1;
                    if(j < n - 1) x = dist[i][j + 1] + 1;
                    dist[i][j] = min(dist[i][j], min(x, y)); 
                }

                ans = max(ans, dist[i][j]);
            }
        }

        if(ans == 0 || ans == INT_MAX) return -1;
        return ans;
    }
};