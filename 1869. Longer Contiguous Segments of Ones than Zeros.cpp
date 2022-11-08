class Solution {
public:
    bool checkZeroOnes(string s) {
        int z = 0, o = 0;
        int flag = 1;
        int curr = 0;
        
        if(s[0] == '0') flag = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                if(flag) curr++;
                else{
                    if(curr > z) z = curr;
                    curr = 1;
                    flag = 1;
                }
            }
            else{
                if(!flag) curr++;
                else{
                    if(curr > o) o = curr;
                    curr = 1;
                    flag = 0;
                }
            }
        }
        
        if(flag){
            if(curr > o) o = curr;
        }
        else{
            if(curr > z) z = curr;
        }
        
        //cout << o << ' ' << z << '\n';
        
        return o > z;
    }
};