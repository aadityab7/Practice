class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        //start from the smaller one and then start by dividing the min by 
        int s1 = str1.size(), s2 = str2.size();
        
        //get all the factors of s and t
        //get all the common factors and then 
        //check them starting from the biggest
        
        int curr = s1;
        if(s2 < curr) curr = s2;
        
        while(curr){
            //check if s1 and s2 are divisible by curr or not
            
            if(s1 % curr == 0 && s2 % curr == 0){
                //check if first curr words of both are equal 
                //and if all the parts of s1 == curr
                
                string x = str1.substr(0, curr);
                
                int flag = 1;
                
                for(int j = 0; j < s1; j += curr){
                    string t = str1.substr(j, curr);
                    if(x != t){
                        flag = 0;
                        break;
                    }
                }
                
                if(flag)
                for(int j = 0; j < s2; j += curr){
                    string t = str2.substr(j, curr);
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