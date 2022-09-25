class Solution {
public:
    bool judgeCircle(string s) {
        int h = 0, v = 0;
        
        for(char c : s){
            if(c == 'U') v++;
            else if(c == 'D') v--;
            else if(c == 'L') h++;
            else h--;
        }
        
        if(!v && !h){
            return true;
        }
        
        return false;
        
    }
};

class Solution {
public:
    bool judgeCircle(string s) {
        int h = 0, v = 0;
        
        for(int i = 0; i < s.size(); i++){
            // if(s[i] == 'U') v++;
            // else if(s[i] == 'D') v--;
            // else if(s[i] == 'L') h++;
            // else h--;
            
            switch(s[i]){
                case 'U' :  v++;
                            break;
                case 'D' :  v--;
                            break;
                case 'L' :  h++;
                            break;
                case 'R' :  h--;
                            break;
            }
            
        }
        
        if(!v && !h){
            return true;
        }
        
        return false;
        
    }
};