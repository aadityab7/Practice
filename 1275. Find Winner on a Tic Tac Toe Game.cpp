class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<int>> arr(3, vector<int>(3,-1));
        
        int ch = 1, r, c, cz, rz;
        string ans = "Draw";
        int i, j;
        
        for(i = 0; i < moves.size(); i++){
            arr[moves[i][0]][moves[i][1]] = ch;
            ch = 1 - ch;
        }
        
        // for(int i = 0; i < 3; i++){
        //     for(int j = 0; j < 3; j++){
        //         cout << arr[i][j] << ' ';
        //     }
        //     cout << '\n';
        // }
            
        for(i = 0; i < 3; i++){
            
            r = 0;
            c = 0;
            rz = 0;
            cz = 0;
            
            for(j = 0; j < 3; j++){
                if(arr[i][j] == 1) r++;    
                if(arr[j][i] == 1) c++;
                
                if(arr[i][j] == 0) rz++;
                if(arr[j][i] == 0) cz++;
            }
            
            if(r == 3 || c == 3) return "A";
            else if(rz == 3 || cz == 3) return "B";
        }
        
        //check for diagonals
        if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2]){
            if(arr[1][1] == 1) return "A";
            else if(arr[1][1] == 0) return "B";
        }
        
        if(arr[0][2] == arr[1][1] && arr[2][0] == arr[1][1]){
            if(arr[1][1] == 1) return "A";
            else if(arr[1][1] == 0) return "B";
        }
        
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                if(arr[i][j] == -1) return "Pending";
            }
        }
        
        return ans;
    }
};