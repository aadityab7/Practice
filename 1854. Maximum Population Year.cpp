class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> mp;

        for(int i = 0; i < logs.size(); i++){
            mp[logs[i][0]]++;
            mp[logs[i][1]]--;
        }

        int ans = mp.begin() -> first;
        int mx = mp.begin() -> second;
        int curr = 0;

        for(auto itr = mp.begin(); itr != mp.end(); itr++){
            curr += itr -> second;
            if(curr > mx){
                mx = curr;
                ans = itr -> first;        
            }
        }

        return ans;
    }
};