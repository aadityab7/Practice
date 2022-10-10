class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        int arr[26] = {};
        
        for(int i = 0; i < words.size(); i++){
            //for each word
            int temp[26] = {};
            for(int j = 0; j < words[i].size(); j++){
               temp[words[i][j] - 'a']++;
            }
            
            if(i){
                for(int j = 0; j < 26; j++){
                    if(temp[j] < arr[j]) arr[j] = temp[j];
                }
            }
            else{
                for(int j = 0; j < 26; j++) arr[j] = temp[j];
            }
        }
        
        vector<string> ans;
        
        for(int i = 0; i < 26; i++){
            while(arr[i]--){
                string s(1,'a'+ i);
                ans.push_back(s);
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string> ans;

        int arr[26];
        int i, j;
        for(i = 0; i < 26; i++) arr[i] = 200;
        
        for(i = 0; i < words.size(); i++){
            //for each word
            int temp[26] = {};
            for(j = 0; j < words[i].size(); j++){
               temp[words[i][j] - 'a']++;
            }
            
            for(j = 0; j < 26; j++){
                if(temp[j] < arr[j]) arr[j] = temp[j];
            }
        }
        
        
        for(i = 0; i < 26; i++){
            while(arr[i]--){
                ans.push_back(string(1,'a'+ i));
            }
        }
        
        return ans;
    }
};