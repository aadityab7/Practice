class Solution {
public:
    int countGoodSubstrings(string s) {
        int ans = 0;
        
        int size = s.size() - 2;
        
        if(size < 1) return ans;
        
        for(int i = 0; i < size; i++){
            if(s[i] != s[i + 1] && s[i] != s[i + 2] && s[i + 1] != s[i + 2]) ans++;
        }
        
        return ans;
    }
};