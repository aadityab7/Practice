class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;
        
        for(int i = 0; i < paths.size(); i++){
            mp[paths[i][0]] = 1;
            
            if(mp.find(paths[i][1]) == mp.end()){
                //not available in the list 
                mp[paths[i][1]] = 0;
            }
        }
        
        string ans = "";
         
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(itr -> second == 0) return itr -> first;
        }
        
        return ans;
    }
};

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_map<string, int> mp;
        
        for(int i = 0; i < paths.size(); i++){
            mp[paths[i][0]] = 1;
            
            if(!mp[paths[i][1]]) mp[paths[i][1]] = 0;
        }
        
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(itr -> second == 0) return itr -> first;
        }
        
        return "";
    }
};