//use backtracking - 13 ms
class Solution {
    vector<int> ans, curr_arrows;
    int mx;

    void helper(int index, int remaining, int score, const vector<int>& alice){
        if(index == 12){
            if(score > mx){
                mx = score;
                if(remaining) curr_arrows[0] = remaining;
                ans = curr_arrows;
                if(remaining) curr_arrows[0] = 0;
            }

            return;
        }

        //bob_loses in this section
        helper(index + 1, remaining, score, alice);

        //bob_wins in this section
        if(remaining > alice[index]){
            curr_arrows[index] = alice[index] + 1;

            helper(index + 1, remaining - curr_arrows[index], score + index, alice);

            curr_arrows[index] = 0;
        }

    }

public:
    vector<int> maximumBobPoints(int numArrows, vector<int>& aliceArrows) {
        mx = 0;
        curr_arrows.resize(12, 0);
        ans = curr_arrows;

        helper(0, numArrows, 0, aliceArrows);

        return ans;      
    }
};