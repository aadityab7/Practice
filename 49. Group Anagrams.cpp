class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //create a map of strings 
        unordered_map<string, vector<string>> mp;
        string s;
        int i, j;
        
        for(i = 0; i < strs.size(); i++){
            //create a unique char array
            int arr[26] = {};
            
            for(j = 0; j < strs[i].size(); j++){
                arr[strs[i][j] - 'a']++;
            }
            
            s = "";
            
            for(j = 0; j < 26; j++){
                s += to_string(arr[j]);
                s += '-';
            }
            
            
            mp[s].push_back(strs[i]);
        }
        
        vector<vector<string>> ans;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            ans.push_back(itr -> second);
        }
        
        return ans;
        
        
    }
};