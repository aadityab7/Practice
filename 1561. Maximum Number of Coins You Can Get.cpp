class Solution {
public:
    int maxCoins(vector<int>& piles) {
        sort(piles.begin(), piles.end());

        int n = piles.size() / 3;
        int sum = 0;

        for(int i = n; i < piles.size(); i+=2) sum += piles[i];

        return sum;
    }
};