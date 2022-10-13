class Solution {
public:
    int removePalindromeSub(string s) {
        //may take upto n^2 in worst case;
        int ans = 0;
        int arr[26] = {};
        int x = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(!arr[s[i] - 'a']){
                arr[s[i] - 'a'] = 1;
                x++;
            }
        }
        
        
        string temp;
        int i, j;
        
        while(s.size() > 0){
            ans++;
            
            temp = "";
            i = 0;            
            j = s.size() - 1;
            
            while(i < j){
                
                if(s[i] == s[j]) i++;
                else temp += s[j];
                
                j--;
            }
            
            s = temp;
        }
        
        return min(ans, x);
    }
};

//at max 26
//bbb