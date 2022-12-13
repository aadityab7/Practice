class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        //work our way from top to bottom 
        //at each row add the smallest path to reach here
        //min at last row will be the ans
        int n = matrix.size(), i, j, min;

        for(i = 1; i < n; i++){
            for(j = 0; j < n; j++){
                //check the smallest path for getting at this element
                min = matrix[i - 1][j];
                if(j - 1 >= 0 && matrix[i - 1][j - 1] < min) min = matrix[i - 1][j - 1];
                if(j + 1 < n && matrix[i - 1][j + 1] < min) min = matrix[i - 1][j + 1];

                matrix[i][j] += min; 
            }
        }

        int ans = matrix[n - 1][0];

        for(i = 0; i < n; i++){
            if(matrix[n - 1][i] < ans) ans = matrix[n - 1][i];
        }

        return ans;
    }
};