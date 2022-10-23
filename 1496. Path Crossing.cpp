class Solution {
public:
    bool isPathCrossing(string path) {
        set<pair<int, int>> st;
        char c;
        int x = 0, y = 0;
        st.insert({0,0});
        int sx, sy;
        
        for(int i = 0; i < path.size(); i++){
            c = path[i];
            
            switch(c){
                case 'N':   
                    sx = 1;
                    sy = 0;
                    break;
                case 'S':   
                    sx = -1;
                    sy = 0;
                    break;
                case 'E':   
                    sx = 0;
                    sy = 1;
                    break;
                case 'W':   
                    sx = 0;
                    sy = -1;
                    break;
            }
            
            x += sx;
            y += sy;
            
            if(st.find({x,y}) != st.end()) return true;
            
            st.insert({x, y});
        }
        
        return false;
    }
};