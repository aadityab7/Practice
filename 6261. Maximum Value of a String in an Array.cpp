class Solution {
public:
    int maximumValue(vector<string>& strs) {
        int ans = 0;
        
        for(int i = 0; i < strs.size(); i++){
            string s = strs[i];
            int curr = 0;
            
            for(int j = 0; j < s.size(); j++){
                
                if(s[j] >= '0' && s[j] <= '9'){
                    
                    curr *= 10;
                    int x = s[j] - '0';
                    //cout << x << '\n';
                    curr += x;
                }
                else{
                    curr = s.size();
                    break;
                }
            }
            
            if(curr > ans) ans = curr;
            //cout << curr << "\n";
        }
        
        return ans;
    }
};