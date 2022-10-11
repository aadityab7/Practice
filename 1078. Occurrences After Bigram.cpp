class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> ans;
        
        stringstream str(text);
        string prev = "", pp = "", word;
        
        while(str >> word){
            if(prev == second && pp == first) ans.push_back(word);
            
            pp = prev;
            prev = word;
        }
        
        return ans;
    }
};