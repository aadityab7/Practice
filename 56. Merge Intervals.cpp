class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        vector<int> curr, rem;

        for(vector<int> i : intervals){
            curr = i;
            rem.clear();

            for(int j = 0; j < ans.size(); j++){
                
                //overlapping sets
                if(max(curr[0], ans[j][0]) <= min(curr[1], ans[j][1])){
                    curr[0] = min(curr[0], ans[j][0]);
                    curr[1] = max(curr[1], ans[j][1]);

                    //sets to be removed
                    rem.push_back(j);
                }

            }

            for(int j = rem.size() - 1; j >= 0; j--) ans.erase(ans.begin() + rem[j]);

            ans.push_back(curr);

            
        }

        return ans;
    }
};