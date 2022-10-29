class Solution {
public:
    string oddString(vector<string>& words) {
        map<string, int> mp;
        map<string, string> m;
        
        for(int i = 0; i < words.size(); i++){
            string s = "";
            
            for(int j = 1; j < words[i].size(); j++){
                s += to_string(words[i][j] - words[i][j-1]);
                s += ' ';
            }
            
            mp[s]++;
            m[s] = words[i];
        }
        
        auto itr = mp.begin();
        auto i = mp.begin();
        i++;
        
        //get str and st
        string ans = m[itr->first];
        
        if(itr -> second > i -> second) ans = m[i->first];
        
        return ans;
    }
};