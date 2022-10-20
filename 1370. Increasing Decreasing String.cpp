class Solution {
public:
    string sortString(string s) {
        int arr[26] = {};
        
        for(int i = 0; i < s.size(); i++){
            arr[s[i] - 'a']++;
        }
        
        //now traverse arr from start to end and from end to start
        string ans = "";
        int flag = 1, done = 0;
        
        while(!done){
            done = 1;
            
            if(flag){
                for(int i = 0; i < 26; i++){
                    if(arr[i]){
                        arr[i]--;
                        done = 0;
                        ans += ('a' + i);
                    }
                }
            }
            else{
                for(int i = 25; i >= 0; i--){
                    if(arr[i]){
                        arr[i]--;
                        done = 0;
                        ans += ('a' + i);
                    }
                }
            }
            
            flag = 1 - flag;
        }
        
        return ans;
    }
};