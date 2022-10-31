class Solution {
public:
    int minOperations(string s) {
        int flag = 1;
        //count1 = start with 0
        //count2 = start with 1;
        
        int count1 = 0, count2 = 0;
        for(int i = 0; i < s.size(); i++){
            if(flag){
                if(s[i] == '1') count1++;
                else count2++;
            }
            else{
                if(s[i] == '0') count1++;
                else count2++;
            }
            
            flag = 1 - flag;
        }
        
        if(count2 < count1) return count2;
        
        return count1;
    }
};