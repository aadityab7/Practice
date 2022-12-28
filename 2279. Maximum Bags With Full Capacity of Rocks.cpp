class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> diff;
        for(int i = 0; i < rocks.size(); i++)
            diff.push_back(capacity[i] - rocks[i]);
        
        sort(diff.begin(), diff.end());

        int ans = 0;

        for(int d : diff){
            if(d <= additionalRocks){
                additionalRocks -= d;
                ans++;
            }
            else break;
        }

        return ans;
    }
};