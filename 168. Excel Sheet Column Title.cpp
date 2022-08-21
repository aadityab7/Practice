class Solution {
public:
    string convertToTitle(int columnNumber) {
        
        string s = "";
        char c;
        
        while(columnNumber > 0){
            //get the last char
            int x = columnNumber % 26;
            //0 is z and 1 is A
            if(x == 0){
                x = 26;
            }
            
            c = (x + 64);
            s += c;
            columnNumber = (columnNumber - x) / 26;
        }
        
        
        //reverse the string
        
        string ans = "";
        int n = s.size();
        
        for(int i = n - 1; i >= 0; i--){
            ans += s[i];
        }
        
        return ans;
    }
};