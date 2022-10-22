class Solution {
public:
    int maxScore(string s) {
        int z = 0, o = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1') o++;
        }
        
        int lz = 0, ro = o;
        int ans = 0;
        
        //ans = 4;
        //ans = 5
        //
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == '0') lz++;
            else ro--;
            
            if((lz + ro) > ans) ans = (lz + ro);
        }
        
        return ans;
        
    }
};