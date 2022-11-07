class Solution {
public:
    string sortSentence(string s) {
        stringstream str(s);
        string word;
        
        vector<string> ans(s.size());
        
        while(str >> word){
            int x = word[word.size() - 1] - '0';
            word[word.size() - 1] = ' ';
            ans[x] = word;
        }
        
        string res = "";
        
        for(int i = 0; i < s.size(); i++){
            res += ans[i];
        }
        
        return res.substr(0, res.size() - 1);
    }
};