class Solution {
public:
    int numRookCaptures(vector<vector<char>>& board) {
        //spot the rook 
        int x = 0, y = 0;
        for(int i = 0; i < 8; i++){
            for(int j = 0; j < 8; j++){
                if(board[i][j] == 'R'){
                    x = i;
                    y = j;
                    break;
                }
            }
        }
        
        int ans = 0;
        //traverse in the four dir from rook 
        //up
        int u = x;
        while(u--){
            if(board[u][y] == 'p'){
                ans++;
                break;
            }
            else if(board[u][y] == 'B'){
                break;
            }
        }
        
        //down
        int d = x;
        while(d < 8){
            if(board[d][y] == 'p'){
                ans++;
                break;
            }
            else if(board[d][y] == 'B'){
                break;
            }
            d++;
        }
        
        int l = y;
        while(l--){
            if(board[x][l] == 'p'){
                ans++;
                break;
            }
            else if(board[x][l] == 'B'){
                break;
            }
        }
        
        int r = y;
        while(r < 8){
            if(board[x][r] == 'p'){
                ans++;
                break;
            }
            else if(board[x][r] == 'B'){
                break;
            }
            r++;
        }
        
        return ans;
        
    }
};