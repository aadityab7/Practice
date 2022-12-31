//HARD - 0ms - DFS

class Solution {
    //important note : empty is initialised as 1 because
    //before going to a cell we do --empty and when we reach destination
    //empty will be -1 otherwise
    
    int empty = 1, ans = 0;

    void dfs(int x, int y, vector<vector<int>> &grid){
        if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size() || grid[x][y] < 0)
return;

        if(grid[x][y] == 2){
            if(empty == 0) ans++;
            return;
        }

        grid[x][y] = -1;
        empty--;
        
        dfs(x + 1, y, grid);
        dfs(x, y + 1, grid);
        dfs(x, y - 1, grid);
        dfs(x - 1, y, grid); 

        grid[x][y] = 0;
        empty++;
    }

public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int start_x = 0, start_y = 0;

        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 0) empty++;
                else if(grid[i][j] == 1){
                    start_x = i;
                    start_y = j;
                }
            }
        }     

        dfs(start_x, start_y, grid);

        return ans;
    }
};