class Solution {
public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int x = 0, y = 0, z = 0;
        int d, i;
        
        for(i = 0; i < firstWord.size(); i++){
            d = firstWord[i] - 'a';
            x *= 10;
            x += d;
        }
        
        for(i = 0; i < secondWord.size(); i++){
            d = secondWord[i] - 'a';
            y *= 10;
            y += d;
        }
        
        for(i = 0; i < targetWord.size(); i++){
            d = targetWord[i] - 'a';
            z *= 10;
            z += d;
        }
        
        return ((x + y) == z);
    }
};