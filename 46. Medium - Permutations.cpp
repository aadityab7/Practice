class Solution {
    
    vector<vector<int>> perm(vector<int> &filled){
        
        vector<vector<int>> res;
        
        for(int i = 0; i < filled.size(); i++){
            
            if(filled[i]){
                int x = i - 10;
                
                vector<int> temp = filled;
                temp[i] = 0;
                
                vector<vector<int>> t = perm(temp);
                
                for(int j = 0; j < t.size(); j++){
                    t[j].push_back(x);
                    res.push_back(t[j]);
                }
                
            }
        }
        
        if(res.size() == 0){
            vector<int> ex;
            res.push_back(ex);
        }
        return res;
    }
    
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> filled(21, 0);
        
        for(int i = 0; i < nums.size(); i++){
            filled[nums[i] + 10] = 1;
        }
        
        return perm(filled);
    }
};