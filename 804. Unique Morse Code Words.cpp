class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> arr{
            ".-","-...","-.-.","-..",
            ".","..-.","--.","....",
            "..",".---","-.-",".-..",
            "--","-.","---",".--.",
            "--.-",".-.","...","-",
            "..-","...-",".--","-..-","-.--","--.."
        };
        
        unordered_set<string> st;
        
        for(int i = 0; i < words.size(); i++){
            string temp = "";
            for(int j = 0; j < words[i].size(); j++){
                //get the morse code and add it to temp;
                temp += arr[words[i][j] - 97];
            }
            st.insert(temp);
        }
        
        return st.size();
    }
};