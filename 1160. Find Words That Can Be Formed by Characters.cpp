class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        int arr[26] = {};
        for(int i = 0; i < chars.size(); i++) arr[chars[i] - 'a']++;
    
        int ans = 0;
        for(int i = 0; i < words.size(); i++){
            int temp[26] = {};
            
            for(int j = 0; j < words[i].size(); j++){
                temp[words[i][j] - 'a']++;
            }
            
            int flag = 1;
            
            for(int j = 0; j < 26; j++){
                if(arr[j] < temp[j]){
                    flag = 0;
                    break;
                }
            }
            
            if(flag) ans += words[i].size();
        }
        
        return ans;
        
    }
};