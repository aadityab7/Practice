class Solution {
public:
    vector<int> distributeCandies(int candies, int num_people) {
        int curr = 0;
        vector<int> ans(num_people, 0);

        while(candies >= curr + 1){
            ans[curr % num_people] += (curr + 1);
            candies -= (curr + 1);
            curr++;
        }

        ans[curr % num_people] += candies;

        return ans;
    }
};

/*

x = 1 + 2 + ... + n

int x = n * (n + 1) / 2;

x = n*n + x
x = n*n + x
x = n*n;

*/