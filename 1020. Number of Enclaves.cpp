class Solution {
    bool dfs(int i, int j, vector<vector<bool>> &visited, const vector<vector<int>> &grid, const int &r, const int &c, int &curr){
        if(grid[i][j] == 0) return true;

        visited[i][j] = true;
        curr++;
        bool res = true;

        //move up 
        if(i){
            if(!visited[i - 1][j]) res &= dfs(i - 1, j, visited, grid, r, c, curr);
        }
        else res = false;

        //move left
        if(j){
            if(!visited[i][j - 1]) res &= dfs(i, j - 1, visited, grid, r, c, curr);
        }
        else res = false;

        //move down
        if((i + 1) < r){
            if(!visited[i + 1][j]) res &= dfs(i + 1, j, visited, grid, r, c, curr);
        }
        else res = false;

        //move right
        if((j + 1) < c){
            if(!visited[i][j + 1]) res &= dfs(i, j + 1, visited, grid, r, c, curr);
        }
        else res = false;

        return res;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0, r = grid.size(), c = grid[0].size();
        vector<vector<bool>> visited(r, vector<bool>(c, false));

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(grid[i][j] && !visited[i][j]){
                    int curr = 0;
                    if(dfs(i, j, visited, grid, r, c, curr)){
                        ans += curr;
                    } 
                }
            }
        }

        return ans;
    }
};

//little cleaner and faster 
class Solution {
    bool dfs(int i, int j, vector<vector<int>> &grid, const int &r, const int &c, int &curr){
        if(grid[i][j] == 0) return true;

        curr++;
        
        //flood the land visited
        grid[i][j] = 0;
        bool res = true;
        
        //if land on edges 
        if(i == 0 || j == 0 || i == r - 1 || j == c - 1) res = false;

        //move up 
        if(i) res &= dfs(i - 1, j, grid, r, c, curr);
        
        //move left
        if(j) res &= dfs(i, j - 1, grid, r, c, curr);
        
        //move down
        if((i + 1) < r) res &= dfs(i + 1, j, grid, r, c, curr);
        
        //move right
        if((j + 1) < c) res &= dfs(i, j + 1, grid, r, c, curr);
        
        return res;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int ans = 0, r = grid.size(), c = grid[0].size();

        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                //if land
                if(grid[i][j]){
                    int curr = 0;
                    if(dfs(i, j, grid, r, c, curr)){
                        ans += curr;
                    } 
                }
            }
        }

        return ans;
    }
};