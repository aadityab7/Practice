class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        //check each row for all the columns
        int r = strs.size(), c = strs[0].size();
        int ans = 0, prev;
        
        for(int i = 0; i < c; i++){
            prev = 0;
            for(int j = 0; j < r; j++){
                //check if >= to prev
                if(strs[j][i] < prev){
                    ans++;
                    break;
                }
                
                prev = strs[j][i];
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        //check each row for all the columns
        int r = strs.size(), c = strs[0].size(), ans = 0, prev, i, j;
        
        for(i = 0; i < c; i++){
            prev = 0;
            for(j = 0; j < r; j++){
                //check if >= to prev
                if(strs[j][i] < prev){
                    ans++;
                    break;
                }
                
                prev = strs[j][i];
            }
        }
        
        return ans;
    }
};