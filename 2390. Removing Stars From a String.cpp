class Solution {
public:
    string removeStars(string s) {
        int curr = 0;

        for(int i = 0; i < s.size(); i++){
            if(s[i] == '*') curr--;
            else s[curr++] = s[i];
        }

        return s.substr(0, curr);
    }
};