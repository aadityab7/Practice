class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int rows = rowSum.size(), cols = colSum.size();
        int x;
        vector<vector<int>> ans(rows, vector<int>(cols));

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                x = min(rowSum[i], colSum[j]);
                
                colSum[j] -= x;
                rowSum[i] -= x;

                ans[i][j] = x;
            }
        }

        return ans;
    }
};