class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        //if the number after flipping the row is more than before flip the row
        //and for each column if by flipping number of ones are greater than before flip 
        int ans = 0;

        int r = grid.size(), c = grid[0].size();

        int mx = (1 << c) - 1;
        //cout << "mx : " << mx << '\n'; 

        vector<int> temp(c);
        temp[c - 1] = 1;

        for(int i = c - 2; i >= 0; i--){
            temp[i] = temp[i + 1] * 2;
        }

        for(int i = 0; i < r; i++){
            int num = 0;

            for(int j = c - 1; j >= 0; j--){
                if(grid[i][j]) num += temp[j];
            }

            // cout << num << ' ' << (mx ^ num) << '\n';

            if((mx ^ num) > num){
                //flip the bits in this row
                for(int j = 0; j < c; j++) grid[i][j] = 1 - grid[i][j];
            }
        }

        //for columns
        for(int i = 0; i < c; i++){
            //count the ones 
            int ones = 0;

            for(int j = 0; j < r; j++){
                if(grid[j][i]) ones++;
            }

            if((r - ones) > ones){
                for(int j = 0; j < r; j++) grid[j][i] = 1 - grid[j][i];
            }
        }

        for(auto row : grid){
            // for(int j : row) cout << j << ' ';
            // cout << '\n';
            for(int i = c - 1; i >= 0; i--){
                if(row[i]) ans += temp[i];
            }
        }

        return ans;
    }
};