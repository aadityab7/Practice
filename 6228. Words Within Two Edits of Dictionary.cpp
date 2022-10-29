class Solution {
public:
    vector<string> twoEditWords(vector<string>& q, vector<string>& d) {
        vector<string> ans;
        int size = q[0].size();
        
        //for each query
        for(int i = 0; i < q.size(); i++){
            
            //check if diff btw arr and any dict arr is less = 2
            int diff;
            
            for(int j = 0; j < d.size(); j++){
                
                diff = 0;
                
                //for this word in dict
                for(int k = 0; k < size; k++){
                    if(q[i][k] != d[j][k]) diff++;
                }
                
                
                if(diff < 3){
                    ans.push_back(q[i]);
                    break;
                }
                
            }//end for this query
            
        }
        
        return ans;
        
    }
};