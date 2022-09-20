class Solution {
public:
    bool checkRecord(string s) {
        int late_count = 0, abs = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == 'L'){
                late_count++;
                if(late_count >= 3){
                    return false;
                }
            }
            else{
                if(s[i] == 'A'){
                    if(abs) return false;
                    abs = 1;
                }
                
                late_count = 0;
            } 
        }
        
        if(abs < 2) return true;
        
        return false;
    }
};