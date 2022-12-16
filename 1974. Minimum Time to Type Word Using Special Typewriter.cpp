//0 ms
class Solution {
public:
    int minTimeToType(string word) {
        int ans = 0;
        int pos = 0;

        for(int i = 0; i < word.size(); i++){
            //move the pointer to location
            int x = abs(word[i] - 'a' - pos);
            int y = 26 - x;

            ans += min(x, y);


            pos = word[i] - 'a';
            //type the word
            ans++;
        }

        return ans;
    }
};