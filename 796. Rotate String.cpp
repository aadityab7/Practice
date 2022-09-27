class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        
        int i = 0;
        int size = s.size();
        
        while(i < size){
            
            if(s[i] == goal[0]){
                //go from j = 0 to the size of goal
                
                int flag = 1;  
                for(int j = 0; j < size; j++){
                    //compare goal[j] and s[i + j % size]
                    if(goal[j] != s[(i + j) % size]){
                        flag = 0;
                        break;
                    }
                }
                
                if(flag) return true;
            }
            
            i++;
        }
        
        return false;
    }
};