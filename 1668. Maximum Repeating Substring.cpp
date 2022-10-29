class Solution {
public:
    int maxRepeating(string s, string word) {
        int max = 0;
        string t = word;
        
        //string::npos is a constant with value = -1
        while(s.find(t) != string::npos){
            t += word;
            max++;
        }
        
        return max;
    }
};