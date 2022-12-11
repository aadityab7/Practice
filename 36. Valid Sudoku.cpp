//55ms
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check if all the elements in rows are unique
        //and check if all the elements in cols are unique  

        vector<vector<int>> b(9, vector<int>(9,0));

        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] != '.'){
                    b[i][j] = board[i][j] - '0';
                }
            }
        }


        for(int i = 0; i < 9; i++){
            int r[10] = {}, c[10] = {};

            for(int j = 0; j < 9; j++){
                if(b[j][i]){
                    
                    if(c[b[j][i]]){
                        return false;
                    }

                    c[b[j][i]] = 1;
                }

                if(b[i][j]){
                    
                    if(r[b[i][j]]){
                        return false;
                    }

                    r[b[i][j]] = 1;
                }

            }
        }

        //check if all elements in 3X3 boxes is unique
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 3; j++){
                int arr[10] = {};
                for(int k = 0; k < 3; k++){
                    for(int l = 0; l < 3; l++){
                        if(b[k + 3 * i][l + 3 * j]){
                            if(arr[b[k + 3 * i][l + 3 * j]]) return false;
                            arr[b[k + 3 * i][l + 3 * j]] = 1;
                        }
                        
                    }
                }
            }
        }

        return true;
    }
};

//faster - 18 ms
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check if all the elements in rows are unique
        //and check if all the elements in cols are unique  
        int i, j, k, l;

        for(i = 0; i < 9; i++){
            int r[10] = {}, c[10] = {};
            for(j = 0; j < 9; j++){
                if(board[j][i] != '.'){
                    if(c[board[j][i] - '0']) return false;
                    c[board[j][i] - '0'] = 1;
                }
                if(board[i][j] != '.'){ 
                    if(r[board[i][j] - '0'])return false;
                    r[board[i][j] - '0'] = 1;
                }
            }
        }

        //check if all elements in 3X3 boxes is unique
        for(i = 0; i < 3; i++){
            for(j = 0; j < 3; j++){
                int arr[10] = {};
                for(k = 0; k < 3; k++){
                    for(l = 0; l < 3; l++){
                        if(board[k + 3 * i][l + 3 * j] != '.'){
                            if(arr[board[k + 3 * i][l + 3 * j] - '0']) return false;
                            arr[board[k + 3 * i][l + 3 * j] - '0'] = 1;
                        }
                        
                    }
                }
            }
        }

        return true;
    }
};