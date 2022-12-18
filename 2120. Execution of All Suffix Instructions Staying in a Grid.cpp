class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans;

        int x, y, count, i, j;
        
        for(i = 0; i < s.size(); i++){
            x = startPos[0];
            y = startPos[1];
            count = 0;
            
            for(j = i; j < s.size(); j++){
                if(s[j] == 'U') x--;
                else if(s[j] == 'L') y--;
                else if(s[j] == 'R') y++;
                else x++;

                if(x == n || x == -1 || y == -1 || y == n) break; 

                count++;
            }

            ans.push_back(count);
        }
        
        return ans;
    }
};