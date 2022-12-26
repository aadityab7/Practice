class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size(), i = 0, j = 0;

        vector<int> rows(r, 0), cols(c, 0);
        vector<vector<int>> ans(r, vector<int>(c));

        for(i = 0; i < r; i++)
            for(j = 0; j < c; j++)
                if(grid[i][j]){
                    rows[i]++;
                    cols[j]++;
                } 
        
        int total = r + c;

        for(i = 0; i < r; i++)
            for(j = 0; j < c; j++)
                ans[i][j] = 2 * rows[i] + 2 * cols[j] - total;
            
        return ans;
    }
};