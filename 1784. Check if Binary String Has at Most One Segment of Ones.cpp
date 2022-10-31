class Solution {
public:
    bool checkOnesSegment(string s) {
        int flag = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '0'){
                flag = 1;
            }
            else{
                if(flag) return false;
            }
        }
        
        return true;
    }
};