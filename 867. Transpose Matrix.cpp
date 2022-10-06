class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        
        vector<vector<int>> ans(c, vector<int>(r));
        
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                ans[j][i] = matrix[i][j];
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>& matrix) {
        int r = matrix.size(), c = matrix[0].size(), i, j;
        
        vector<vector<int>> ans(c);
        
        for(i = 0; i < r; i++){
            for(j = 0; j < c; j++){
                ans[j].push_back(matrix[i][j]);
            }
        }
        
        return ans;
    }
};