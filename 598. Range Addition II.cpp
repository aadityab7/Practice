class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int min_x = m;
        int min_y = n;
        for(int i = 0; i < ops.size(); i++){
            if(ops[i][0] < min_x){
                min_x = ops[i][0];
            }
            if(ops[i][1] < min_y){
                min_y = ops[i][1];
            }
        }
        return min_x * min_y;
    }
};

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        int x = m, y = n;
        for(int i = 0; i < ops.size(); i++){
            x = min(x, ops[i][0]);
            y = min(y, ops[i][1]);
        }
        return x * y;
    }
};