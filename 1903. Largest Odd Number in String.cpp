class Solution {
public:
    string largestOddNumber(string num) {
        string ans = "";
        
        for(int i = num.size() - 1; i >= 0; i--){
            int x = num[i] - '0';
            if(x % 2){
                ans = num.substr(0, i + 1);
                break;
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    string largestOddNumber(string num) {
        for(int i = num.size() - 1; i >= 0; i--){
            if((num[i] - '0') % 2){
                return num.substr(0, i + 1);
            }
        }
        return "";
    }
};