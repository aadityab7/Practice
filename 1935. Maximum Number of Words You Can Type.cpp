class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int arr[26] = {};
        
        for(int i = 0; i < brokenLetters.size(); i++) arr[brokenLetters[i] - 'a']++;
        
        stringstream str(text);
        string word;
        
        int ans = 0, flag;
        
        while(str >> word){
            flag = 1;
            
            for(int i = 0; i < word.size(); i++){
                if(arr[word[i] - 'a']){
                    flag = 0;
                    break;
                }
            }    
            
            if(flag) ans++;
        }
        
        return ans;
    }
};


//0 ms
class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int arr[26] = {};
        
        for(int i = 0; i < brokenLetters.size(); i++) arr[brokenLetters[i] - 'a']++;
        
        stringstream str(text);
        string word;
        
        int ans = 0, flag = 1;
        
        for(int i = 0; i < text.size(); i++){
            if(text[i] == ' '){
                if(flag) ans++;
                flag = 1;
            }
            else{
                if(arr[text[i] - 'a']) flag = 0;
            }
        }
        
        if(flag) ans++;
        
        return ans;
    }
};