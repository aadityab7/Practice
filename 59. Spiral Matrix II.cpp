//0 ms
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n));
        
        int i = 0, j = 0;
        int total = n * n;
        int count = 1;
        int dir = 0;
        int min_x = 0, min_y = 1, max_x = n - 1, max_y = n - 1;

        vector<int> upd_i = {0, 1, 0, -1}, upd_j = {1, 0, -1, 0};

        while(count <= total){
            
            ans[i][j] = count;

            if(dir == 0 && j == max_x){
                dir = 1;
                max_x--;
            }
            else if(dir == 1 && i == max_y){ 
                dir = 2;
                max_y--;
            }
            else if(dir == 2 && j == min_x){ 
                dir = 3;
                min_x++;
            }
            else if(dir == 3 && i == min_y){
                dir = 0;
                min_y++;
            }

            i += upd_i[dir];
            j += upd_j[dir];
            count++;
        }

        return ans;
    }
};