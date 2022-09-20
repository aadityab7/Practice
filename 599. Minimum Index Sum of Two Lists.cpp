class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        
        for(int i = 0; i < list1.size(); i++){
            mp[list1[i]] = i;
        }
        
        vector<string> ans;
        vector<string> temp;
        
        int min_sum = INT_MAX;
        
        string s;
        for(int i = 0; i < list2.size(); i++){
            s = list2[i];
            
            //if found
            if(mp.find(s) != mp.end()){
                
                //
                if((mp[s] + i) < min_sum){
                    
                    ans = temp;
                    ans.push_back(list2[i]);
                    min_sum = mp[s] + i;
                    
                }        
                else if((mp[s] + i) == min_sum){
                    ans.push_back(list2[i]);
                }
                
            }//end found if
            
        }//end for
        
        
        return ans;
    }
};  