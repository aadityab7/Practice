class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        string ans = "";
        while(i < word1.size() && j < word2.size()){
            if(ans.size() % 2) ans += word2[j++];
            else ans += word1[i++];
        }
        
        while(i < word1.size()) ans += word1[i++];
        while(j < word2.size()) ans += word2[j++];

        return ans;
    }
};