class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
         //for each element in top row 
        //check cooresponding diagonal
        
        for(int x = 0; x < c - 1; x++)
            for(int i = 0, j = x; i < r && j < c; i++, j++)
                if(matrix[i][j] != matrix[0][x]) return false;
        
        
        for(int x = 1; x < r - 1; x++)
            for(int j = 0, i = x; i < r && j < c; i++, j++)
                if(matrix[i][j] != matrix[x][0]) return false;
        
        
        return true;
    }
};

//compare with prev diagonal element
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        for(int i = 1; i < matrix.size(); i++)
            for(int j = 1; j < matrix[0].size(); j++)
                if(matrix[i][j] != matrix[i - 1][j - 1]) return false;
        
        return true;
    }
};