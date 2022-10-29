class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int arr[26] = {};
        for(int i = 0; i < allowed.size(); i++) arr[allowed[i] - 'a'] = 1;
        
        int ans = 0;
        
        for(int i = 0; i < words.size(); i++){
            int a[26] = {};
            
            for(int j = 0; j < words[i].size(); j++){
                a[words[i][j] - 'a'] = 1;
            }
            
            //if all the chars in a are also present in arr then ans++
            int flag = 1;
            
            for(int j = 0; j < 26; j++){
                if(a[j] && !arr[j]){
                    flag = 0;
                    break;
                }
            }
            
            if(flag) ans++;
        }
        
        return ans;
    }
};