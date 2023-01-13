class Solution {
public:
    bool areNumbersAscending(string s) {
        stringstream str(s);
        string word;

        int curr, prev = -1;

        while(str >> word){
            if(word[0] >= '0' && word[0] <= '9'){
                curr = stoi(word);
                if(curr <= prev) return false;
                prev = curr;
            }
        }

        return true;
    }
};


class Solution {
public:
    bool areNumbersAscending(string s) {
        stringstream str(s);
        string word;
        int prev = -1;

        while(str >> word){
            if(word[0] >= '0' && word[0] <= '9'){
                if(stoi(word) <= prev) return false;
                prev = stoi(word);
            }
        }

        return true;
    }
};