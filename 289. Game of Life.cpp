//6 ms
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size(), c = board[0].size();

        vector<vector<int>> b = board;
        vector<pair<int, int>> pos;

        pos.push_back({-1, -1});
        pos.push_back({-1, 0});
        pos.push_back({-1, 1});
        pos.push_back({0, -1});
        pos.push_back({0, 1});
        pos.push_back({1, -1});
        pos.push_back({1, 0});
        pos.push_back({1, 1});


        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                int count = 0;

                for(auto &p : pos){
                    int x = i + p.first;
                    int y = j + p.second;

                    if(((x >= 0) && (x < r)) && ((y >= 0) && (y < c))){
                        //cout << x << ' ' << y << '\n';
                        if(board[x][y] == 1) count++;
                    }
                        
                }

                if(board[i][j]){
                    //alive
                    if(count < 2) b[i][j] = 0;
                    else if (count > 3) b[i][j] = 0;
                } 
                else{
                    //dead
                    if(count == 3) b[i][j] = 1;
                }

                //b[i][j] = count;

            }
        }

        board = b;
    }
};

//Condensed Version - 0 ms
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size(), c = board[0].size();

        vector<vector<int>> b = board;
        
        vector<pair<int, int>> pos = {
            {-1, -1},
            {-1, 0},
            {-1, 1},
            {0, -1},
            {0, 1},
            {1, -1},
            {1, 0},
            {1, 1}
        };

        int count, i, j, x, y;
        for(i = 0; i < r; i++){
            for(j = 0; j < c; j++){
                count = 0;

                for(auto &p : pos){
                    x = i + p.first;
                    y = j + p.second;

                    if(x >= 0 && x < r && y >= 0 && y < c)
                        if(board[x][y] == 1) count++;
                    
                        
                }

                if(board[i][j]){
                    if(count < 2) b[i][j] = 0;
                    else if (count > 3) b[i][j] = 0;
                } 
                else{
                    if(count == 3) b[i][j] = 1;
                }

            }
        }

        board = b;
    }
};

//In place without using extra space - 5 ms
class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int r = board.size(), c = board[0].size();
        
        // vector<pair<int, int>> pos = {
        //     {-1, -1},
        //     {-1, 0},
        //     {-1, 1},
        //     {0, -1},
        //     {0, 1},
        //     {1, -1},
        //     {1, 0},
        //     {1, 1}
        // };

        vector<int> mover = {-1,-1,-1,0,0,1,1,1};
        vector<int> movec = {-1,0,1,-1,1,-1,0,1};

        //-1 = alive was dead
        //0 = dead
        //1 = alive
        //2 = dead was alive

        int count, i, j, x, y;
        
        for(i = 0; i < r; i++){
            for(j = 0; j < c; j++){
                count = 0;

                // for(auto &p : pos){
                //     x = i + p.first;
                //     y = j + p.second;

                //     if(x >= 0 && x < r && y >= 0 && y < c)
                //         if(board[x][y] == 1 || board[x][y] == 2) count++;    
                // }

                for(int k = 0; k < 8; k++){
                    x = i + mover[k];
                    y = j + movec[k];
                    if(x >= 0 && x < r && y >= 0 && y < c)
                        if(board[x][y] == 1 || board[x][y] == 2) count++;
                }

                if(board[i][j] == 1){
                    if(count < 2) board[i][j] = 2;
                    else if (count > 3) board[i][j] = 2;
                } 
                else if(board[i][j] == 0){
                    if(count == 3) board[i][j] = -1;
                }

            }
        }

        //put correct values 
        for(i = 0; i < r; i++){
            for(j = 0; j < c; j++){
                if(board[i][j] == 2) board[i][j] = 0;
                else if(board[i][j] == -1) board[i][j] = 1;
            }
        }

    }
};