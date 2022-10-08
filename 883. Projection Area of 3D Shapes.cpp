class Solution {
public:
    int projectionArea(vector<vector<int>>& grid) {
        int n = grid.size();
        
        //base area = how many places on the grid have blocks
        //side view 1 = max of rows 
        //side view 2 = max of cols
        vector<int> col(n,0);
        
        int total = 0;
        for(int i = 0; i < n; i++){
            int mr = 0;
            
            for(int j = 0; j < n; j++){
                if(grid[i][j]) total++;
                
                if(grid[i][j] > col[j]) col[j] = grid[i][j];
                
                if(grid[i][j] > mr) mr = grid[i][j];
            }
            
            
            total += mr;
        }
        
        for(int i = 0; i < n; i++) total += col[i];
        
        //now we have the base area & side 1
        
        
        
        return total;
    }
};