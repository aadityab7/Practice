class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();

        //max in each row
        vector<int> row(n, 0);
        
        //max in each col
        vector<int> col(n, 0);

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] > row[i]) row[i] = grid[i][j];
                if(grid[i][j] > col[j]) col[j] = grid[i][j];
            }
        }

        int ans = 0;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                ans += min(row[i], col[j]);
                ans -= grid[i][j];

                // if(row[i] > grid[i][j] && col[j] > grid[i][j]){
                //     ans += min(row[i], col[j]);
                //     ans -= grid[i][j];
                // }
            }
        }

        return ans;
    }
};