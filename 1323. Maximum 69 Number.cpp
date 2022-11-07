class Solution {
public:
    int maximum69Number (int num) {
        string n = to_string(num);
        int ans = 0, flag = 1;
        
        for(int i = 0; i < n.size(); i++){
            
            if(flag && n[i] == '6'){
                n[i] = '9';
                flag = 0;
            }
            
            ans *= 10;
            ans += n[i] - '0';
            
        }
        
        return ans;
    }
};