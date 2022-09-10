class Solution {
public:
    int firstUniqChar(string s) {
        int arr[26];
        
        for(int i = 0; i < 26; i++){
            arr[i] = -2;
        }
        
        for(int i = 0; i < s.size(); i++){
           
            if(arr[s[i] - 'a'] == -2){
                arr[s[i] - 'a'] = i;
            }
            else{
                arr[s[i] - 'a'] = -1;
            }
            
        }
            
        int ans = -1;
        for(int i = 0; i < 26; i++){ 
            
            if(arr[i] >= 0){
                if(ans == -1){
                    ans = arr[i];
                }
                else if(arr[i] < ans){
                    ans = arr[i];
                }
            }
            
        }
        
        return ans;
        
    }
};