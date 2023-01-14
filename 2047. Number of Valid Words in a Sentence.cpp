class Solution {
public:
    int countValidWords(string sentence) {
        stringstream str(sentence);
        string word;

        int ans = 0;
        while(str >> word){
            int flag = 1;
            int hyphen = 0;
            int punch = 0;

            for(int i = 0; i < word.size(); i++){
                if(word[i] >= 'a' && word[i] <= 'z') continue;
                else if(word[i] >= '0' && word[i] <= '9'){
                    flag = 0;
                    break;
                }
                else if(word[i] == '-'){
                    if(hyphen || i == 0 || i == word.size() - 1){
                        flag = 0;
                        break;
                    }
                    else if(word[i - 1] < 'a' || word[i - 1] > 'z'){
                        flag = 0;
                        break;
                    }
                    else if(word[i + 1] < 'a' || word[i + 1] > 'z'){
                        flag = 0;
                        break;
                    }

                    hyphen = 1;
                }
                else{
                    //punctuation
                    if(punch){
                        flag = 0;
                        break;
                    }
                    else if(i != word.size() - 1){
                        flag = 0;
                        break;
                    }

                    punch = 1;
                }
            }


            if(flag) ans++;
        }

        return ans;
    }
};