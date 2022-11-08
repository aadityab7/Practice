class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans = 0, r;
        int row = accounts.size(), col = accounts[0].size();
        
        for(int i = 0; i < row; i++){
            r = 0;
            
            for(int j = 0; j < col; j++) r+= accounts[i][j];
            
            if(r > ans) ans = r;
        }
        
        return ans;
    }
};