class Solution {
public:
    int countOdds(int low, int high) {
        int x = high - low;

        if(low % 2 == 0){
            if(x == 0) return 0;

            x--;
        }

        return (x/2) + 1;
    }
};