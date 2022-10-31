class Solution {
public:
    string mergeAlternately(string word1, string word2) {
    
        int i = 0, j = 0;
        int flag = 1;
        string ans = "";
        
        while(i < word1.size() || j < word2.size()){
            if(i == word1.size()){
                ans += word2[j++];
            }
            else if(j == word2.size()){
                ans += word1[i++];
            }
            else{
                if(flag) ans += word1[i++];
                else ans += word2[j++];
                
                flag = 1 - flag;
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    string mergeAlternately(string word1, string word2) {
    
        int i = 0, j = 0;
        int flag = 1;
        string ans = "";
        
        while(i < word1.size() && j < word2.size()){
            if(flag) ans += word1[i++];
            else ans += word2[j++];
                
            flag = 1 - flag;
        }
        
        while(i < word1.size()) ans += word1[i++];
        
        while(j < word2.size()) ans += word2[j++];
        
        return ans;
    }
};