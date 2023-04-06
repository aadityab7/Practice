class Solution {
    bool dfs(int i, int j, vector<vector<bool>> &visited, const vector<vector<int>> &grid){
        //return true if it is water 
        if(grid[i][j]) return true;

        //if it is land proceed further
        visited[i][j] = true;
        bool res = true;
        int r = grid.size(), c = grid[0].size();
        
        //even if we know that answer is false for this island
        //we must mark all the connected blocks as visited

        //that direction exists and it has not already been visited

        //move up
        if(i){
            if(!visited[i - 1][j]) res &= dfs(i - 1, j, visited, grid);
        } 
        else res = false;

        //move left
        if(j){
            if(!visited[i][j - 1]) res &= dfs(i, j - 1, visited, grid);
        } 
        else res = false;

        //move down
        if(i < r - 1){
            if(!visited[i + 1][j]) res &= dfs(i + 1, j, visited, grid);
        } 
        else res = false;

        //move right
        if(j < c - 1){
            if(!visited[i][j + 1]) res &= dfs(i, j + 1, visited, grid);
        } 
        else res = false;

        return res;
    }

public:
    int closedIsland(vector<vector<int>>& grid) {
        int r = grid.size(), c = grid[0].size(), ans = 0;
        vector<vector<bool>> visited(r, vector<bool>(c, false));

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(!grid[i][j] && !visited[i][j]){
                    if(dfs(i, j, visited, grid)) ans++; 
                }
            }
        }

        return ans;
    }
};