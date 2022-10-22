class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int r = grid.size();
        int c = grid[0].size();
        
        vector<vector<int>> ans(r, vector<int>(c,0));
        int t = r * c;
        
        k = k % t;
        cout << k << '\n';
        
        //we need to set i and j at appropreate pos 
        
        int i = 0, j = 0;
        int flag = 0;
        
        while(i < r){
            j = 0;
            
            while(j < c){
                if(k == 0){
                    flag = 1;
                    break;
                }
                
                k--;
                
                j++;
            }
    
            if(flag) break;
            i++;
        }
        
        cout << i << ' ' << j << '\n';
        
        //we now have i and j from where to start
        for(int x = 0; x < r; x++){
            for(int y = 0; y < c; y++){
                
                ans[i][j] = grid[x][y];
                j++;
                if(j == c){
                    i++;
                    j = 0;
                    if(i == r) i = 0;
                }
            }
        }
        
        return ans;
        
    }
};