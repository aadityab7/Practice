class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        int s1 = str1.size(), s2 = str2.size(), flag, j;
        int curr = s1;
        if(s2 < curr) curr = s2;
        
        string x, t;
        
        while(curr){
            if(!(s1 % curr) && !(s2 % curr)){
                //check if first curr words of both are equal 
                //and if all the parts of s1 == curr
                
                x = str1.substr(0, curr);
                
                flag = 1;
                
                for(j = 0; j < s1; j += curr){
                    t = str1.substr(j, curr);
                    if(x != t){
                        flag = 0;
                        break;
                    }
                }
                
                if(flag)
                for(j = 0; j < s2; j += curr){
                    t = str2.substr(j, curr);
                    if(x != t){
                        flag = 0;
                        break;
                    }
                }
                
                if(flag) return x;
            }
            
            curr--;
        }
        
        return "";
    }
};