class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        
        //unordered_map <pair<int, int>, int> mp;
        map <pair<int,int>, int> mp;
        
        for(int i = 0; i < dominoes.size(); i++){
            if(dominoes[i][0] < dominoes[i][1]){
                mp[{dominoes[i][0], dominoes[i][1]}]++;
            }
            else{
                mp[{dominoes[i][1], dominoes[i][0]}]++;
            }
        }
        
        int ans = 0;
        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            if(itr -> second > 1){
                int x = itr -> second;
                ans += (x) * (x - 1) / 2;
            }
        }
        
        return ans;
        
    }
};