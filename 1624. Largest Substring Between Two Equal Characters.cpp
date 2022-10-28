class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        int ans = -1;
        int size = s.size();
        int first, last, i, j, dist;
        char c;
        
        
        for(j = 0; j < 26; j++){
            //find first and last of this char
            c = 'a' + j;
            first = 0;
            last = 0;
            
            for(i = 0; i < size; i++){
                if(s[i] == c){
                    first = i;
                    break;
                }
            }
            
            for(i = size - 1; i >= 0; i--){
                if(s[i] == c){
                    last = i;
                    break;
                }
            }
            
            //we found two chars
            if(first != last){
                dist = last - first - 1;
                if(dist > ans) ans = dist;
            }
            
        }
        
        return ans;
    }
};

//we can find first and last of each character and if no pair 
//exist then ans = -1