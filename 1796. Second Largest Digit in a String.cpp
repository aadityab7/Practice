class Solution {
public:
    int secondHighest(string s) {
        int max = -1;
        int max2 = -1;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= '0' && s[i] <= '9'){
                int x = s[i] - '0';
                if(x > max){
                    max2 = max;
                    max = x;
                }
                else if(x < max && x > max2){
                    max2 = x;
                }
            }
        }
        
        return max2;
    }
};