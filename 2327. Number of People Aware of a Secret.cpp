class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        //the amount of people that will share the secret that day
        vector<long long> share(n + 1, 0);
        long long curr = 0;
        share[1] = 1;
        int MOD = 1000000007;

        for(int i = 2; i <= n; i++){
            //how many new people will learn the secret today
            //how many people are going to share the secret today = curr
            //how many new people are going to start sharing secret today
            //how many people will forget and not share secret today
            curr = (curr + share[max(i - delay, 0)] - share[max(i - forget, 0)] + MOD) % MOD;

            share[i] = curr;
        }

        //in the past days how many people have learned the secret who will still remember it
        long long ans = 0;

        for(int i = 0; i < forget; i++){
            ans = (ans + share[n - i]) % MOD;
        }

        return ans;
    }
};