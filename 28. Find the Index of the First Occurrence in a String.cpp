class Solution {
    vector<int> create_lps(string pattern){
        int n = pattern.size();
        vector<int> lps(n, 0);
        int i = 1, j = 0;

        while(i < n){
            if(pattern[i] == pattern[j]){
                lps[i] = j + 1;
                i++;
                j++;
            }
            else{
                if(j != 0) j = lps[j - 1];
                else i++;
            }
        } 

        return lps;
    }

public:
    int strStr(string haystack, string needle) {
        if(needle == "") return 0;

        int n = haystack.size(), m = needle.size();
        vector<int> lps = create_lps(needle);
        int i = 0, j = 0;
        while(i < n){
            if(haystack[i] == needle[j]){
                i++;
                j++;
                if(j == m) return i - m;

            }
            else{
                if(j != 0) j = lps[j - 1];
                else i++;
            }
        }

        return -1;
    }
};

/////////////////////////////////////////////////////////////////////////////////////

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