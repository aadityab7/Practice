class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        vector<int> row(r);
        vector<int> col(c);
        
        //max in col and min in row
        
        for(int i = 0; i < c; i++){
            col[i] = matrix[0][i];
        }
        
        for(int i = 0; i < r; i++){
            int min = INT_MAX;
            
            for(int j = 0; j < c; j++){
                if(matrix[i][j] < min) min = matrix[i][j];
                if(matrix[i][j] > col[j]) col[j] = matrix[i][j];
            }
            
            row[i] = min;
        }
        
        vector<int> ans;
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                if(row[i] == col[j]) ans.push_back(row[i]);
            }
        }
        
        return ans;
    }
};