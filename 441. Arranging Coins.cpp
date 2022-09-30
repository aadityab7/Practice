class Solution {
public:
    int arrangeCoins(int n) {
        int k = 0;
        long num = 1;
        
        while(num <= n){
            k++;
            num += (k + 1);
        }
        
        return k;
    }
};

/*
n * (n + 1) / 2 = x
0 -> 0
1 -> 1
3 -> 2
6 -> 3
10 -> 4
2x = n * n + n
*/

class Solution {
public:
    int arrangeCoins(int n) {
        return (int)(sqrt((8 * (long)n) + 1) - 1)/2;
    }
};