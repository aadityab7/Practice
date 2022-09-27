class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int curr = 0, lines = 1, size;
        
        for(char c : s){
            //get the width of c and then add it curr width
            //if curr > 100 
            //then get a new line and c to it
            size = widths[c - 'a'];
            curr += size;
            
            if(curr > 100){
                lines++;
                curr = size;
            }
        }
        
        return {lines, curr};
    }
};

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        vector<int> ans(2);
        ans[0] = 1;
        ans[1] = 0;
        
        for(int i = 0; i < s.size(); i++){
            ans[1] += widths[s[i] - 97];
            if(ans[1] > 100){
                ans[0]++;
                ans[1] = widths[s[i] - 97];
            }
        }
        
        return ans;
    }
};