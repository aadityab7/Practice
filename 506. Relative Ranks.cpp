class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size());
        map<int, int> mp;
        
        for(int i = 0; i < score.size(); i++){
            mp[score[i]] = i;
        }
        
        int i = 0;
        string temp;
        
        for(auto itr = mp.rbegin(); itr != mp.rend(); itr++){
            
            if(i > 2){
                temp = to_string(i + 1);
            }
            else if(i == 0){
                temp = "Gold Medal";
            }    
            else if(i == 1){
                temp = "Silver Medal";
            }
            else{
                temp = "Bronze Medal";
            }
            
            ans[itr -> second] = temp;
            i++;
        }
        
        return ans;
    }
};