class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0, ans = 0;

        for(char c : s){
            if(c == '(') count++;
            else{
                if(count == 0) ans++;
                else count--;
            }
        } 

        return ans + count;
    }
};