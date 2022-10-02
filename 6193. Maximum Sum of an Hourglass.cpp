class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int total;
        int max = 0;
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(j){
                    grid[i][j] += grid[i][j - 1]; 
                }
            }
        }
        
        for(int i = 0; i <= n - 3; i++){
            for(int j = 0; j <= m - 3; j++){
                //this will go to the begining of every hour glass and calc sum of hourglass
                total = grid[i][j + 2] + grid[i + 1][j + 1] - grid[i + 1][j] + grid[i + 2][j + 2];
                
                if(j){
                    total -= grid[i][j - 1];
                    total -= grid[i + 2][j - 1];
                }
                
                if(total > max) max = total;
            }
        }
        
        return max;
    }
};