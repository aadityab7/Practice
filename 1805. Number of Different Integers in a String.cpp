class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> ans;
        string s = "";
        
        for(int i = 0; i < word.size(); i++){
            
            if(word[i] >= '0' && word[i] <= '9'){
                if(s != "0") s += word[i];
                else{
                    s = "";
                    s += word[i];
                }
            }
            else{
                if(s != "") ans.insert(s);
                
                s = "";
            }
        }
        
        if(s != "") ans.insert(s);
        
        return ans.size();
    }
};