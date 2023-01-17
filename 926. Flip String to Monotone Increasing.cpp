class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int zeros = 0, prevo = 0;

        for(char &c : s)
            if(c == '0') zeros++;

        int ans = zeros;

        for(char &c : s){
            if(c == '1') prevo++;
            else zeros--;
            
            ans = min(ans, prevo + zeros);
        }

        return ans;
    }
};


//check for each position 
//every thing before is zero and everything after is 1