//0ms
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        map<int, vector<string>> mp = {
            {2, {"a", "b", "c"}},
            {3, {"d", "e", "f"}},
            {4, {"g", "h", "i"}},
            {5, {"j", "k", "l"}},
            {6, {"m", "n", "o"}},
            {7, {"p", "q", "r", "s"}},
            {8, {"t", "u", "v"}},
            {9, {"w", "x", "y", "z"}}
        };
        
        vector<string> ans;
       
        
        for(int i = 0; i < digits.size(); i++){
            //for each digit take all the strings present in ans and then append the alphabets and push them to 
            vector<string> temp;
            int x = digits[i] - '0';
            
            if(ans.size()){
                for(int i = 0; i < ans.size(); i++){
                    int size = mp[x].size();
                    for(int j = 0; j < size; j++){
                        string tp = ans[i] + mp[x][j];
                        temp.push_back(tp);
                    }
                }
            }
            else{
                int size = mp[x].size();
                for(int i = 0; i < size; i++){
                    temp.push_back(mp[x][i]);
                }
            }
            
            ans = temp;
            
        }
        
        
        return ans;
    }
};