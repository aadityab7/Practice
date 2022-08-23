class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int arr[127] = {};
        char c, ch;
        bool ans = true;
        
        for(int i = 0; i < s.size(); i++){
            //if that character is not already mapped then just map it to the char in t
            c = s[i];
            ch = t[i];
            
            if(arr[c] == 0){
                arr[c] = ch + 1;
            }
            else{
                if(arr[c] != (ch + 1)){
                    ans = false;
                    break;
                }
            }
        }
        
        //no two chars should map to the same char
        int count[127] = {};
        
        for(int i = 0; i < 127; i++){
            c = arr[i];
            if(c > 0) {
                count[c - 1]++;
                if(count[c - 1] > 1){
                    ans = false;
                    break;
                }
            }
        }
        
        return ans;

    }
};