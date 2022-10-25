class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int c = grid[0].size();
        int ans = 0;
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = c - 1; j >= 0; j--){
                if(grid[i][j] >= 0) break;
                
                ans++;
            }
        }
        
        return ans;
    }
};