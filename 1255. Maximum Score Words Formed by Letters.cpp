//HARD
//IDK what is it called - using dfs or Backtracking
class Solution {
    int ans = 0;

    void helper(int index, const vector<string>& words, vector<int> &letter_count, vector<int> &score, int curr){
        if(index == words.size()){
            ans = max(ans, curr);
            return;
        }

        //without using this word
        helper(index + 1, words, letter_count, score, curr);
        
        //check if we can use this word
        int flag = 1;
        vector<int> temp = letter_count;
        for(char c : words[index]){
            if(temp[c - 'a']){
                temp[c - 'a']--;
                curr += score[c - 'a'];
            }
            else{
                flag = 0;
                break;
            }
        }

        if(flag){
            helper(index + 1, words, temp, score, curr);
        }

    }
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<int> letter_count(26, 0);
        for(char c : letters) letter_count[c - 'a']++;

        helper(0, words, letter_count, score, 0);

        return ans;
    }
};