class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int total = 0;
        int n = mat.size();
        
        for(int i = 0; i < n; i++){
            total += mat[i][i];
            if(i != n - i - 1) total += mat[i][n - i - 1];
        }
        
        return total;
    }
};