class Solution {
public:
    int surfaceArea(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size(), r, c;
        
        for(int i = 0; i < n; i++){
            r = 0;
            c = 0;
            
            for(int j = 0; j < n; j++){
                if(grid[i][j]) ans+=2;
                
                ans += abs(grid[i][j] - r);
                ans += abs(grid[j][i] - c);
            
                r = grid[i][j];
                c = grid[j][i];
            }
            
            ans += r;
            ans += c;
        }
        
        
        return ans;
        
    }
};

//4 + 4 = 8
//1 + 1 + 2
//3 + 1 + 4
//1 + 2 + 3
//2 + 2 + 4