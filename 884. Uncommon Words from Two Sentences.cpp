class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        
        stringstream str(s1);
        string word;
        
        while(str >> word){
            mp[word]++;
        }
        
        stringstream st(s2);
        while(st >> word){
            mp[word]++;
        }
        
        vector<string> ans;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(itr -> second == 1) ans.push_back(itr->first);
        }
        
        return ans;
    }
};


class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp;
        
        string word = "";
        
        for(char c : s1){
            
            if(c == ' '){
                mp[word]++;
                word = "";
            }
            else{
                word += c;
            }
            
        }
        
        mp[word]++;
        
        word = "";
        for(char c : s2){
            if(c == ' '){
                mp[word]++;
                word = "";
            }
            else{
                word += c;
            }
        }
        
        mp[word]++;
        
        vector<string> ans;
        for(auto itr = mp.begin(); itr != mp.end(); itr++) 
            if(itr -> second == 1) ans.push_back(itr->first);
        
        
        return ans;
    }
};