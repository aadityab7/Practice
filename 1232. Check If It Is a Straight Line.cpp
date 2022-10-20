class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& c) {
        //get the slope and check for slope between every two points
        int x = (c[1][0] - c[0][0]);
        int y = (c[1][1] - c[0][1]);
        
        float slope, temp;
        int flag = 0, t = 0;
        
        if(x) slope = (float)y / x;
        else flag = 1;
        
        for(int i = 2; i < c.size(); i++){
            t = 0;
            
            y = (c[i][1] - c[i - 1][1]);
            x = (c[i][0] - c[i - 1][0]);
            
            if(x) temp = (float)y / x;
            else t = 1;
            
            //cout << slope << ' ' << temp << '\n';
            
            if(flag){
                if(!t) return false;
            }
            else if(slope != temp) return false;
        }
        
        return true;
    }
};

//slope = 1 / 0;
