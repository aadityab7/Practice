class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0, zeros = 0, ones = 0;
        int o = 0, z = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                ones++;
                if(zeros >= ones){
                    ans++;
                }
                
                if(z){
                    z = 0;
                    o = 0;
                }
                o++;
            }
            else{
                if(ones){
                    ones = 0;
                    zeros = 0;
                }
                zeros++;
                
                z++;
                if(o >= z){
                    ans++;
                }
            }
        }
        
        return ans;
        
    }
};

/*
01 10
0011 1100
000111 111000


*/

class Solution {
public:
    int countBinarySubstrings(string s) {
        int ans = 0;
        int one = 0, zeros = 0;
        int o = 0, z = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] == '1'){
                one = 1;
                if(zeros){
                    ans++;
                    zeros--;
                }
                
                if(z){
                    z = 0;
                    o = 0;
                }
                o++;
            }
            else{
                if(one){
                    one = 0;
                    zeros = 0;
                }
                zeros++;
                
                z = 1;
                if(o){
                    ans++;
                    o--;
                }
            }
        }
        
        return ans;
        
    }
};

/*
01 10
0011 1100
000111 111000


*/