class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        string ans = "";
        //for nR chars move down and then for nR - 2 move up 
        //1 = down
        int rev = 0;
        
        vector<vector<char>> row(numRows);
        int x = 0;
        
        for(int i = 0; i < s.size(); i++){
            row[x].push_back(s[i]);
            
            if(rev){
                //reverse 
                x--;
                if(x == 0) rev = 0;
            }   
            else{
                x++;
                if(x == numRows){
                    x -= 2;
                    if(x) rev = 1;
                }
            }
            
        }
        
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < row[i].size(); j++){
                //cout << row[i][j] << ' ';
                ans += row[i][j];
            }
            // cout << '\n';
        }
        
        return ans;
    }
};

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        
        string ans = "";
        
        vector<vector<char>> row(numRows);
        int rev = 1;
        int x = 0;
        
        for(int i = 0; i < s.size(); i++){
            row[x].push_back(s[i]);
            
            if(x == 0 || x == numRows - 1) rev = 1 - rev;
            
            if(rev) x--;
            else x++;
        }
        
        for(int i = 0; i < numRows; i++){
            for(int j = 0; j < row[i].size(); j++){
                ans += row[i][j];
            }
        }
        
        return ans;
    }
};