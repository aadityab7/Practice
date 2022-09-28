class Solution {
public:
    string mostCommonWord(string s, vector<string>& banned) {
        unordered_map<string, int> mp;
        unordered_set<string> st(banned.begin(), banned.end());
        
        string temp = "";
        for(int i = 0; i < s.size(); i++){
            if(temp != "" && (s[i] == ',' || s[i] == '.' || s[i] == ' ' || s[i] == '!' || s[i] == '?' || s[i] == ';')){
                mp[temp]++;
                temp = "";
            }
            else{
                if(s[i] >= 'A' && s[i] <= 'Z') temp += s[i] + 32;
                else if(s[i] >= 'a' && s[i] <= 'z')temp += s[i];
            }
        }
        
        if(temp != ""){
            mp[temp]++;
        }
        
        int max = 0;
        string ans = ""; 
        //we have a set of banned words and a set of all the other words
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            //
            if(st.find(itr -> first) == st.end()){
                //word not found in banned words
                if(itr -> second > max){
                    max = itr -> second;
                    ans = itr -> first;
                }
            }
        }
        
        return ans;
    }
};