class Solution {
public:
    string reversePrefix(string word, char ch) {
        int pos = 0;

        for(int i = 0; i < word.size(); i++){
            if(word[i] == ch){
                pos = i;
                break;
            }
        }

        //reverse string from 0 to pos
        for(int i = 0; i <= pos / 2; i++){
            char temp = word[i];
            word[i] = word[pos - i];
            word[pos - i] = temp;
        }

        return word;
    }
};