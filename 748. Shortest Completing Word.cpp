class Solution {
public:
    string shortestCompletingWord(string s, vector<string>& words) {
        //create an array of required chars in licence plate
        int arr[26] = {};
        
        for(int i = 0; i < s.size(); i++){
            if(s[i] >= 'a' && s[i] <= 'z'){
                arr[s[i] - 'a']++;
            }
            else if(s[i] >= 'A' && s[i] <= 'Z'){
                arr[s[i] - 'A']++;
            }
        }
        
        string ans = "";
        int min = INT_MAX;
        int flag = 1;
        
        for(int i = 0; i < words.size(); i++){
            //for each word create a char array 
            int a[26] = {};
            
            for(int j = 0; j < words[i].size(); j++){
                a[words[i][j] - 'a']++;
            }
            
            flag = 1;
            for(int j = 0; j < 26; j++){
                if(a[j] < arr[j]){
                    flag = 0;
                    break;
                }
            }
            
            if(flag){
                if(words[i].size() < min){
                    min = words[i].size();
                    ans = words[i];
                }
            }
        }
        
        return ans;
        
    }
};