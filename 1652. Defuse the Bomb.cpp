class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size(), x, j;
        vector<int> ans(n, 0);
        if(k == 0) return ans;
        
        for(int i = 0; i < n; i++){
            x = k;
            if(x > 0){
                //sum of next k terms 
                j = i;
                while(x--){
                    j++;
                    if(j == code.size()) j = 0;
                    ans[i] += code[j];
                } 
            }
            else{
                //sum of prev k terms 
                j = i;
                x = 0 - x;;
                while(x--){
                    j--;
                    if(j == -1) j = code.size() - 1;
                    ans[i] += code[j];
                }
            }
        }
        
        return ans;
    }
};