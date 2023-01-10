class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        //use dynamic programming to figure out how many squares can end (right - bottom)
        //at this point - also it is the size of biggest square

        for(int i = 1; i < matrix.size(); i++){
            for(int j = 1; j < matrix[0].size(); j++){
                if(matrix[i][j]){
                    //find min between (i - 1, j - 1) (i, j - 1) (i - 1, j)
                    matrix[i][j] += min(matrix[i - 1][j - 1], min(matrix[i][j - 1], matrix[i - 1][j]));
                }
            }
        }

        int ans = 0;

        for(auto m : matrix){
            for(int x : m){
                ans += x; 
            }
        }

        return ans;
    }
};