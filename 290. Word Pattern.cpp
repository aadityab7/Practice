class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int m = s.size();
        
        //create a map of alphabets and associate words with it 
        //then check if the corrresponding word is in the same order or not
        
        unordered_map<char, string> alpha;
        unordered_map<string, char> words;
        
        string word;
        char c;
        
        int j = 0;
        
        for(int i = 0; i < pattern.size(); i++){
            //check if a word is associated or not
            //if not then add it to the map
            //else check if the same word is associated or not
            //if not ans = false
            
            //extract the word

            word = "";
            c = pattern[i];
            
            while((j < m) && (s[j] != ' ')){
                word += s[j];
                j++;
            }
            
            while((j < m) && (s[j] == ' ')){
                j++;
            }
            
            if(word == ""){
                return false;
            }
            
            auto it = words.find(word);
            
            if(it == words.end()){
                words[word] = c;
            }
            else{
                if(c != words[word]){
                    return false;
                }
            }
            
            auto itr = alpha.find(c);
            
            if(itr == alpha.end()){
                alpha[c] = word;
            }
            else{
                if(word != alpha[c]){
                    return false;
                }
            }
        }
        
        if(j < m){
            return false;
        }
        
        return true;
    }
};