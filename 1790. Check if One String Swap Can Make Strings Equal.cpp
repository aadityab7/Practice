class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int pos1 = -1, pos2 = -1;
        
        for(int i = 0; i < s1.size(); i++){
            if(s1[i] != s2[i]){
                if(pos1 == -1) pos1 = i;
                else if(pos2 == -1) pos2 = i;
                else return false;
            }
        }
        
        if(pos1 == -1 && pos2 == -1) return true;
        
        if(pos1 != -1 && pos2 != -1){
            if((s1[pos1] == s2[pos2]) && (s1[pos2] == s2[pos1])) return true;

        }
        
        return false;
    }
};