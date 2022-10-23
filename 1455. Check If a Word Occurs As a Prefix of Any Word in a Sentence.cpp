class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream str(sentence);
        
        string word;
        int i = 1;
        
        int size = searchWord.size();
        
        while(str >> word){
            if(word[0] == searchWord[0] && word.size() >= size){
                string x = word.substr(0, size);
                if(x == searchWord) return i;
            }
            
            i++;
        }
        
        return -1;
    }
};