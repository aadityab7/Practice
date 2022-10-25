class Solution {
public:
    string modifyString(string s) {
        //just place any other char than the char before and after
        int size = s.size();
        
        for(int i = 0; i < size; i++){
            //we only have to replace ? marks
            
            if(s[i] == '?'){
                //check for a b and c 
                //one of them must fit
                
                if((i == 0 || s[i - 1] != 'a') && (i == size - 1 || s[i + 1] != 'a')){
                    s[i] = 'a';
                }
                else if((i == 0 || s[i - 1] != 'b') && (i == size - 1 || s[i + 1] != 'b')){
                    s[i] = 'b';
                }
                else{
                    s[i] = 'c';
                }
            }    
        }
        
        return s;
    }
};