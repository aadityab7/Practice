class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        //create a map coresponding to order
        // unordered_map<char, int> mp;
        // for(int i = 0; i < 26; i++){
        //     mp[order[i]] = i;
        // }
        
        int i, j, mp[26], k, diff;;
        for(i = 0; i < 26; i++){
            mp[order[i] - 'a'] = i; 
        }
        
        for(i = 1; i < words.size(); i++){
            
            //check with prev
            //words[i] && words[i - 1]
            
            k = 0;
            diff = 0;
            
            for(j = 0; j < words[i-1].size() && j < words[i].size(); j++, k++){
                //cout << words[i][j] << '\n';
                if(mp[words[i][j] - 'a'] < mp[words[i - 1][j] - 'a']) return false;
                else if(mp[words[i][j] - 'a'] > mp[words[i - 1][j] - 'a']){
                    diff = 1;
                    break;
                }
            }
            
            if(!diff && k != words[i -1].size()) return false;
            
        }
        
        
        return true;
    }
};