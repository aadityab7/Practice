class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> ans;
        
        int start = 0, end = 0;
        
        for(int i = 1; i < s.size(); i++){
            
            if(s[i] != s[start]){
               
                end = i - 1;
                if((end - start) > 1)
                    ans.push_back({start, end});
                
                
                start = i;
                
            }//end if (when sequence ends)
            
            
        }
        
        if(s.size() - 1 - start > 1){
            end = s.size() - 1;
            ans.push_back({start, end});
        }
        
        return ans;
    }
};