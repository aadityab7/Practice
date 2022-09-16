class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        //string ans = "";
        string temp = "";
        int curr = 0;
        
        for(int i = s.size() - 1; i >= 0; i--){
            if(s[i] == '-'){
                continue;
            }
            
            if(curr == k){
                temp += '-';
                curr = 0;
            }
            
            //temp += s[i].to
            
            if(s[i] >= 'a'){
                temp += s[i] - 32;
            }
            else{
                temp += s[i];
            }
           
            curr++;
        }
        
        reverse(temp.begin(), temp.end());
        
        return temp;
    }
};