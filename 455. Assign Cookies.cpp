class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        //sort
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int ans = 0;
        int j = 0;
        
        for(int i = 0; i < s.size(); i++){
            if(j == g.size()){
                break;
            }
            if(s[i] >= g[j]){
                ans++;
                j++;
            }
        }
        
        return ans;
    }
};