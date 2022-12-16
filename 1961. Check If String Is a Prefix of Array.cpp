class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string temp = "";
    
        if(s == "") return true;
        
        for(int i = 0; i < words.size(); i++){
            temp += words[i];
            if(temp == s) return true;
        }

        return false;
    }
};

//0 ms
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        string temp = "";
        if(s == temp) return true;
        for(string x : words){
            temp += x;
            if(temp == s) return true;
        }

        return false;
    }
};