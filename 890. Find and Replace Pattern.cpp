class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;

        //convert strings into a string (sequence) of numbers 
        int size = pattern.size(), curr = 0;
        
        unordered_map<char, int> mp;
        
        string P_temp = "", temp;
        for(char c : pattern){
            if(mp.find(c) == mp.end()) mp[c] = curr++;
        
            P_temp += to_string(mp[c]) + " ";
        }

        for(string s : words){
            curr = 0;
            temp = "";
            mp.clear();

            for(char c : s){
                if(mp.find(c) == mp.end()) mp[c] = curr++;
                
                temp += to_string(mp[c]) + " ";
            }

            if(temp == P_temp) ans.push_back(s);
        }

        return ans;

    }
};