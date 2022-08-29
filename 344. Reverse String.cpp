class Solution {
public:
    void reverseString(vector<char>& s) {
        char c;
        for(int i = 0; i < (s.size() / 2); i++){
            //swap the values
            c = s[i];
            s[i] = s[s.size() - i - 1];
            s[s.size() - i - 1] = c;
        }
    }
};

//ANOTHER ONE 
class Solution {
public:
    void reverseString(vector<char>& s) {
        char c;
        for(int i = 0; i < (s.size() / 2); i++){
            //swap the values
            // c = s[i];
            // s[i] = s[s.size() - i - 1];
            // s[s.size() - i - 1] = c;
            
            swap(s[i], s[s.size() - i - 1]);
        }
    }
};