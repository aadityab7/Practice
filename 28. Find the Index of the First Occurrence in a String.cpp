class Solution {
public:
    int strStr(string haystack, string needle) {
        
        int ans = -1, flag = 1;
        
        if(needle == ""){
            ans = 0;
            return ans;
        }
        
        int n = needle.size();
        int m = haystack.size();
        
        for(int i = 0; i < m; i++){
                
            if(haystack[i] == needle[0] && (i + n - 1 < m ) && haystack[i + n - 1] == needle[n - 1]){
                    flag = 1;
                
                    for(int j = 0; j < n; j++){
                        
                        if(needle[j] != haystack[j + i]){
                            flag = 0;
                            break;
                        }
                        
                    }
                
                    if(flag == 1){
                        return i;
                    }
                
            }
            
        } 
        
        return ans;
    }
};