class Solution {
public:
    int maxPower(string s) {
        int ans = 0, last = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] != s[last]){
                if(i - last > ans) ans = i - last;
                last = i;
            }
        }
        
        if(s.size() - last > ans) ans = s.size() - last;
        
        return ans;
    }
};