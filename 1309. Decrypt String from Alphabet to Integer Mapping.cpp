class Solution {
public:
    string freqAlphabets(string s) {
        int i = s.size() - 1, t;
        string ans = "", x;
        
        while(i >= 0){
            if(s[i] == '#'){
                //get the next two numbers 
                i--;
                
                x = s.substr(i - 1, 2);
                t = stoi(x);
                
                i--;
                
                ans += t -1 + 'a';
            }
            else{
                ans += s[i] - '1' + 'a';
            }
            
            i--;
        }
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};