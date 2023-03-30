class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int curr = 0, sum = 0, ans = 0;

        sort(satisfaction.begin(), satisfaction.end());

        for(int i = 0; i < satisfaction.size(); i++){
            curr += satisfaction[i] * (i + 1);
            sum += satisfaction[i];
        }

        ans = max(ans, curr);

        for(int i = 0; i < satisfaction.size(); i++){
            curr = curr - sum;
            sum -= satisfaction[i];
            ans = max(ans, curr);
        }

        return ans;
    }
};