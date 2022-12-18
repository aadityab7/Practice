class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev = 0, count, i, j;

        for(i = 0; i < bank.size(); i++){

            count = 0;

            for(j = 0; j < bank[0].size(); j++)
                if(bank[i][j] == '1') count++;
   

            if(count){
                ans += prev * count;
                prev = count;  
            }
        }

        return ans;
    }
};