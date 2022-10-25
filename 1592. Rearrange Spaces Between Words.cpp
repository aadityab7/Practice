class Solution {
public:
    string reorderSpaces(string text) {
        //count the no. of spaces and number of words
        string ans = "";
        
        int spaces = 0;
        int size = text.size();
        
        vector<string> words;
        
        int i = 0;
        while(i < size){
            while(i < size && text[i] == ' '){
                spaces++;
                i++;
            }
            
            if(i < size && text[i] != ' '){
                string w = "";
                while(i < size && text[i] != ' '){
                    w += text[i];
                    i++;
                }
                
                words.push_back(w);
            }
        }
        
        int x = 0;
        
        if(words.size() > 1) x = spaces / (words.size() - 1);
      
        for(int i = 0; i < words.size(); i++){
            ans += words[i];
            
            if(i < words.size() - 1){
                //add x spaces
                for(int j = 0; j < x; j++, spaces--) ans += ' ';
            }
            else{
                //add remaining all spaces
                for(int j = 0; j < spaces; j++) ans += ' ';
            }
        }
        
        return ans;
        
    }
};