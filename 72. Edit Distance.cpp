class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        vector<int> dp(n + 1, -1), dpPrev(n + 1, -1);

        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(i == 0){
                    dp[j] = j;
                }
                else if(j == 0){
                    dp[j] = i;
                }
                else if(word1[i - 1] == word2[j - 1]){
                    dp[j] = dpPrev[j - 1];
                }
                else{
                    dp[j] = min(dpPrev[j], min(dp[j - 1], dpPrev[j - 1])) + 1;
                }
            }

            //swap dp and dpPrev
            vector<int> temp = dp;
            dp = dpPrev;
            dpPrev = temp;
        }

        return dpPrev[n];
    }
};

/*
def minDistance(self, s1: str, s2: str) -> int:
        m, n = len(s1), len(s2)
        dp, dpPrev = [-1] * (n+1), [-1] * (n+1)
        for i in range(m+1):
            for j in range(n+1):
                if i == 0:
                    dp[j] = j  # Need to insert `j` chars to become s2[:j]
                elif j == 0:
                    dp[j] = i  # Need to delete `i` chars to become ""
                elif s1[i-1] == s2[j-1]:
                    dp[j] = dpPrev[j-1]
                else:
                    dp[j] = min(dpPrev[j], dp[j-1], dpPrev[j-1]) + 1
            dp, dpPrev = dpPrev, dp
        return dpPrev[n]
*/